#include "test.h"
#include <map>
#include <string>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <vector>
#include <assert.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
int main() {
    //FILE *fp = fopen("/Users/bianshujun/Desktop/test.log", "r");
    FILE * fp = fopen("/Users/bianshujun/Desktop/a.txt", "r+");
    if (fp == NULL) {
        cerr << "file error" << endl;
        exit(1);
    }
 
    fseek(fp, 1, SEEK_SET);
    fwrite("ggg", 1, 3, fp);
 
    fclose(fp);
 
    return 0;
/*
    std::vector<region_t *> region_list;
    for (int i = 0; i < 3; i++) {

        segment_t* tempSeg = new segment_t();
        tempSeg->seg_name = "data";
        tempSeg->seg_size = 3 * (i + 1);
        char* data = new char[10];
        sprintf(data, "prae_%d_suff", i);
        tempSeg->data = data;

        region_t* tempRegion = new region_t();
        tempRegion->segment = tempSeg;
        tempRegion->offset = i + 3;
        tempRegion->size = 4;
        std::string tempStr = "String";
        tempStr += i;
        tempRegion->undo_data = &tempStr;

        region_list.push_back(tempRegion);
    }

    // for (int i = 0; i < 3; i++) {
    //     std::cout << (char*)region_list[i]->segment->data << std::endl;
    // }


    trans_header_t txheader;
    trans_end_t txender;
    txheader.recordnum = 0;
    txheader.length = sizeof(trans_header_t) + sizeof(trans_end_t);
    txheader.tid = 79;

    for (std::vector<region_t *>::iterator it = region_list.begin(); it!=region_list.end(); it++)
    {
        txheader.recordnum++;
        txheader.length += (sizeof(int)+strlen((*it)->segment->seg_name)+sizeof(int)*2+(*it)->size);
    }
    
    txender.recordnum = txheader.recordnum;
    txender.length = txheader. length;        
    txender.tid = 79;
    
    fwrite(&txheader, 1, sizeof(trans_header_t), fp);
    
    for (std::vector<region_t *>::iterator it = region_list.begin(); it!=region_list.end(); it++)
    {
        char buf[256];
        int len;
        len = strlen((*it)->segment->seg_name);
        memcpy(buf, (char*)&len, sizeof(int));
        memcpy(buf + sizeof(int), (*it)->segment->seg_name, len);
        memcpy(buf + sizeof(int)+len, &((*it)->offset), sizeof(int));
        memcpy(buf + sizeof(int)+len+ sizeof(int), &((*it)->size), sizeof(int));
        fwrite(buf, 1, sizeof(int)+len+ sizeof(int)*2, fp);
        fwrite((char *)(*it)->segment->data + (*it)->offset, 1, (*it)->size, fp);
    }
    fwrite(&txender, 1, sizeof(trans_end_t), fp);
    fclose(fp);
*/
    //fp = fopen("/Users/bianshujun/Desktop/test.log", "r");
/*
    std::vector<logrecordheader_t *> record_list;

    while(!feof(fp))
    {
       trans_header_t r_txheader;
       fread(&r_txheader, sizeof(trans_header_t), 1, fp);
    std::cout<< r_txheader.recordnum << std::endl;

       for (int i = 0; i < r_txheader.recordnum; i++) {
            //std::cout << i << std::endl;
        logrecordheader_t* record = new logrecordheader_t();
        int segnameLen;
        fread(&segnameLen, sizeof(int), 1, fp);
        fread(&(record->segmentname), segnameLen, 1, fp);
            // std::cout << (char*)record->segmentname << std::endl;

        fread(&(record->region_offset), sizeof(int), 1, fp);
        fread(&(record->region_size), sizeof(int), 1, fp);
            // std::cout << record->region_offset << "   " << record->region_size << std::endl;

        record->data = (void*)malloc(record->region_size);
        fread(record->data, record->region_size, 1, fp);
        // std::cout << (char*)record->data << std::endl;
        record_list.push_back(record);
        }

    trans_end_t r_txender;
    fread(&r_txender, sizeof(trans_header_t), 1, fp);
    if (r_txender.tid != r_txheader.tid || 
        r_txender.length != r_txheader.length ||
        r_txender.recordnum != r_txheader.recordnum) {
        std::cout << record_list.size() << std::endl;
        for (std::vector<logrecordheader_t *>::iterator it = record_list.end() - r_txheader.recordnum;
            it != record_list.end(); it++) {
            free((*it)->data);
            free(*it);            
            //delete a pointer in struct?
        }
        record_list.erase(record_list.end() - r_txheader.recordnum, record_list.end());
    }

    r_txheader.recordnum = 0;
    r_txender.recordnum = 0;
}
fclose(fp);
*/
//std::cout << record_list[0]->segmentname << std::endl;
// std::cout << record_list.size() << std::endl;

    //std::string fileName = record_list[0]->segmentname;


system( "read -n 1 -s -p \"Press any key to continue...\"" );

}