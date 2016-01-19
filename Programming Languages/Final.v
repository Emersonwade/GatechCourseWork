Require Export Hoare.
Require Export Imp.
Require Export Types.
Require Export Smallstep.

(*Imperative Summation*)
(*
  {{ X = n }}
  I ::= 0;;
  Z ::= 0;;
  WHILE  I  <>  X+1  DO
    I ::= I + 1;;
    Z ::= Z + X
  END;;
  Y ::= 0;;
  WHILE Z<>0 Do
    Y ::= Y + 1;;
    Z ::= Z - 2
  END
  {{2 * Y = n * (S n)}}

  {{X = n}} ->>
  {{0 = 0 * n /\ X = n}}
  I ::=0 ;;
  {{0 = I * n /\ X = n}}
  Z ::= 0;;
  {{Z = I * n /\ X = n}}

  WHILE I <> X + 1 DO
    {{Z = I * n /\ X = n /\ I <> X + 1}} ->>
    {{Z + X = (I + 1) * n /\ X = n}}
    I ::= I + 1;;
    {{Z + X = I * n /\ X = n}}
    Z ::= Z + X
    {{Z = I * n /\ X = n}}
  END

  {{Z = I * n /\ X = n /\ I = X + 1}} ->>
  {{Z = n * (n + 1)}} ->>
  {{2 * 0 + Z = n * (n + 1)}}
  Y ::= 0;;
  {{2 * Y + Z = n * (n + 1)}}
  WHILE Z <> 0 DO
    {{2 * Y + Z = n *(n + 1) /\ Z <> 0}} ->>
    {{2 * (Y + 1) + (Z - 2) = n *(n + 1)}}
    Y ::= Y + 1;;
    {{2 * Y + (Z - 2) = n * (n + 1)}}
    Z ::= Z - 2
    {{2 * Y + Z = n * (n + 1)}}
  END
  
  {{2 * Y + Z = n * (n + 1) /\ (Z = 0)}} ->>
  {{2 * Y = n * (n + 1)}} ->>
  {{2 * Y = n * (S n)}}
*)

(*Types*)
Inductive tm : Type :=
  | ttrue : tm
  | tfalse : tm
  | tif : tm -> tm -> tm -> tm
  | tzero : tm
  | tplus : tm-> tm -> tm
  | tsucc : tm -> tm
  | tpred : tm -> tm
  | tiszero : tm -> tm.


Reserved Notation "t1 '==>' t2" (at level 40).

Inductive step : tm -> tm -> Prop :=
  | ST_IfTrue : forall t1 t2,
      (tif ttrue t1 t2) ==> t1
  | ST_IfFalse : forall t1 t2,
      (tif tfalse t1 t2) ==> t2
  | ST_If : forall t1 t1' t2 t3,
      t1 ==> t1' ->
      (tif t1 t2 t3) ==> (tif t1' t2 t3)
  | ST_Succ : forall t1 t1',
      t1 ==> t1' ->
      (tsucc t1) ==> (tsucc t1')
  | ST_PlusZero : forall t1,
    nvalue t1 ->
    tplus tzero t1 ==> t1
  |ST_PlusSucc : forall t1 t1',
    nvalue t1 -> nvalue t1' ->
    tplus (tsucc t1) t1' ==> tplus t1 (tsucc t1')
  | ST_Plus : forall t0 t1 t2,
    t0 ==> t1 ->
    tplus t2 t0 ==> tplus t2 t1
 | ST_Plus2: forall t0 t1 t2,
    t0 ==> t1 ->
    (tplus t0 t2) ==> (tplus t1 t2)
  | ST_PredZero :
      (tpred tzero) ==> tzero
  | ST_PredSucc : forall t1,
      nvalue t1 ->
      (tpred (tsucc t1)) ==> t1
  | ST_Pred : forall t1 t1',
      t1 ==> t1' ->
      (tpred t1) ==> (tpred t1')
  | ST_IszeroZero :
      (tiszero tzero) ==> ttrue
  | ST_IszeroSucc : forall t1,
       nvalue t1 ->
      (tiszero (tsucc t1)) ==> tfalse
  | ST_Iszero : forall t1 t1',
      t1 ==> t1' ->
      (tiszero t1) ==> (tiszero t1')

where "t1 '==>' t2" := (step t1 t2).


Inductive ty : Type := 
  | TBool : ty
  | TNat : ty.
  
Reserved Notation "'|-' t '\in' T" (at level 40).

Inductive has_type : tm -> ty -> Prop :=
  | T_True : 
       |- ttrue \in TBool
  | T_False : 
       |- tfalse \in TBool
  | T_If : forall t1 t2 t3 T,
       |- t1 \in TBool ->
       |- t2 \in T ->
       |- t3 \in T ->
       |- tif t1 t2 t3 \in T
  | T_Zero : 
       |- tzero \in TNat
  | T_Succ : forall t1,
       |- t1 \in TNat ->
       |- tsucc t1 \in TNat
  | T_Pred : forall t1,
       |- t1 \in TNat ->
       |- tpred t1 \in TNat
  | T_Iszero : forall t1,
       |- t1 \in TNat ->
       |- tiszero t1 \in TBool
  | T_Plus : forall t0 t1,
       |- t0 \in TNat ->
       |- t1 \in TNat ->
       |- tplus t0 t1 \in TNat

where "'|-' t '\in' T" := (has_type t T).


Hint Constructors has_type.

Theorem progress : forall t T,
  |- t \in T ->
  value t \/ exists t', t ==> t'.

(** **** Exercise: 3 stars (finish_progress)  *)
(** Complete the formal proof of the [progress] property.  (Make sure
    you understand the informal proof fragment in the following
    exercise before starting -- this will save you a lot of time.) *)

Proof with auto.
  intros t T HT.
  has_type_cases (induction HT) Case...
  (* The cases that were obviously values, like T_True and
     T_False, were eliminated immediately by auto *)
  Case "T_If".
    right. inversion IHHT1; clear IHHT1.
    SCase "t1 is a value".
    apply (bool_canonical t1 HT1) in H.
    inversion H; subst; clear H.
      exists t2...
      exists t3...
    SCase "t1 can take a step".
      inversion H as [t1' H1].
      exists (tif t1' t2 t3)...
  Case "T_Succ". inversion IHHT.
    SCase "t1 is a value". inversion H; clear H.
      SSCase "t1 is a bvalue". solve by inversion 2.
      SSCase "t1 is a nvalue". left...
    SCase "t1 can take a step".
     right. inversion H as [t' H']. exists (tsucc t')...
  Case "T_Pred". inversion IHHT.
    SCase "t1 is a value". inversion H; clear H.
      SSCase "t1 is a bvalue". solve by inversion 2.
      SSCase "t1 is a nvalue". right. inversion H0; eauto.
    SCase "t1 can take a step".
      right. inversion H as [t' H']. exists (tpred t')...
  Case "T_Iszero". right. inversion IHHT.
    SCase "t1 is a value". inversion H; clear H.
      SSCase "t1 is a bvalue". solve by inversion 2.
      SSCase "t1 is a nvalue". inversion H0.
        SSSCase "t1 is tzero". exists ttrue...
        SSSCase "t1 is tsucc t". exists tfalse...
    SCase "t1 can take a step".
      inversion H as [t' H']. exists (tiszero t')...
  Case "T_Plus".
      inversion IHHT1.
      SCase "t0 is a value". inversion H; clear H.
        SSCase "t0 is a bvalue". solve by inversion 2.
        SSCase "t0 is a nvalue". inversion H0.
          SSSCase "t0 is tzero". 
            inversion IHHT2.
            SSSSCase "t1 is a value". inversion H1; clear H1.
              SSSSSCase "t1 is a bvalue". solve by inversion 2.
              SSSSSCase "t1 is a nvalue". inversion H2.
                SSSSSSCase "t1 is tzero". right. exists tzero...
                SSSSSSCase "t1 is tsucc t". right. rewrite H3. exists t1...
           SSSSCase "t1 can take a step".
             inversion H1 as [t' H1']. right. exists (tplus tzero t')...
        SSSCase "t0 is not tzero". right.
          inversion IHHT2.
          SSSSCase "t1 is a value". inversion H2; clear H1. assert (nvalue t1).
          apply nat_canonical. assumption. assumption.
          exists (tplus t (tsucc t1)). constructor. assumption. assumption.
          exists (tplus t (tsucc t1)). constructor. assumption. assumption.
          SSSSCase "t1 can take a step".
            inversion H2 as [t' H1']. exists (tplus (tsucc t) t')...
   SCase "t1 can take a step". right. 
            inversion H as [t' H']. exists (tplus t' t1)...
Qed.
Theorem preservation : forall t t' T,
  |- t \in T ->
  t ==> t' ->
  |- t' \in T.

(** **** Exercise: 2 stars (finish_preservation)  *)
(** Complete the formal proof of the [preservation] property.  (Again,
    make sure you understand the informal proof fragment in the
    following exercise first.) *)

Proof with auto.
  intros t t' T HT HE.
  generalize dependent t'.
  has_type_cases (induction HT) Case; 
         (* every case needs to introduce a couple of things *)
         intros t' HE; 
         (* and we can deal with several impossible
            cases all at once *)
         try (solve by inversion).
    Case "T_If". inversion HE; subst; clear HE.
      SCase "ST_IFTrue". assumption.
      SCase "ST_IfFalse". assumption.
      SCase "ST_If". apply T_If; try assumption.
        apply IHHT1; assumption.
       Case "T_Succ".
      inversion HE; subst...
    Case "T_Pred".
      inversion HE; subst...
      assert (forall t, nvalue t -> has_type t TNat).
        intros. induction H. constructor.
        constructor. apply IHnvalue.
      apply H...
    Case "T_Iszero".
      inversion HE; subst...
    Case "T_Plus".
      inversion HE; subst... constructor. inversion HT1; subst...
      constructor. assumption.
Qed.