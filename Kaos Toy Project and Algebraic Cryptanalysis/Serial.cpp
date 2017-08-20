
#include <bitset>
#include "ToyKg.h"


static std::pair<u32, u32> Solve(const u8 *pbA, const u8 *pbB)
{
    std::bitset<32> x;
    std::bitset<32> y;
    //std::bitset<256> A;
    //std::bitset<256> B;
    u8 A[256] = {0};
    u8 B[256] = {0};
    u32 i, j;
    
    // Move array to bitset, for easy access to individual bits
    for(i=0; i < 32; ++i)
    {
        for(j=0; j < 8; ++j)
        {
            A[i*8+j] = (pbA[i] >> j)&1;
            B[i*8+j] = (pbB[i] >> j)&1;
        }
    }
        
    // Find y, bit by bit.
    do
    {
    	if(A[0]^1) { y[0] = (A[0]&B[0]^A[1]^A[248]^B[0]^B[1]^B[248]); break; }
    	if(B[0]^B[9]) { y[0] = (A[0]&A[9]^A[0]&B[0]^A[9]&B[0]^A[0]&B[9]^A[9]&B[9]^B[0]&B[9]^A[0]^A[1]^A[10]^B[1]^B[9]^B[10]); break; }
    	if(B[0]^B[18]) { y[0] = (A[0]&A[18]^A[0]&B[0]^A[18]&B[0]^A[0]&B[18]^A[18]&B[18]^B[0]&B[18]^A[0]^A[1]^A[19]^B[1]^B[18]^B[19]); break; }
    	if(B[0]^B[27]) { y[0] = (A[0]&A[27]^A[0]&B[0]^A[27]&B[0]^A[0]&B[27]^A[27]&B[27]^B[0]&B[27]^A[0]^A[1]^A[28]^B[1]^B[27]^B[28]); break; }
    	if(B[0]^B[36]) { y[0] = (A[0]&A[36]^A[0]&B[0]^A[36]&B[0]^A[0]&B[36]^A[36]&B[36]^B[0]&B[36]^A[0]^A[1]^A[37]^B[1]^B[36]^B[37]); break; }
    	if(B[0]^B[45]) { y[0] = (A[0]&A[45]^A[0]&B[0]^A[45]&B[0]^A[0]&B[45]^A[45]&B[45]^B[0]&B[45]^A[0]^A[1]^A[46]^B[1]^B[45]^B[46]); break; }
    	if(B[0]^B[54]) { y[0] = (A[0]&A[54]^A[0]&B[0]^A[54]&B[0]^A[0]&B[54]^A[54]&B[54]^B[0]&B[54]^A[0]^A[1]^A[55]^B[1]^B[54]^B[55]); break; }
    } while(0);
    
    do
    {
    	if(A[248]^1) { y[1] = (A[248]&B[248]^A[240]^A[249]^B[240]^B[248]^B[249]); break; }
    	if(B[1]^B[248]) { y[1] = (A[1]&A[248]^A[1]&B[1]^A[248]&B[1]^A[1]&B[248]^A[248]&B[248]^B[1]&B[248]^A[2]^A[248]^A[249]^B[1]^B[2]^B[249]); break; }
    	if(B[10]^B[248]) { y[1] = (A[10]&A[248]^A[10]&B[10]^A[248]&B[10]^A[10]&B[248]^A[248]&B[248]^B[10]&B[248]^A[11]^A[248]^A[249]^B[10]^B[11]^B[249]); break; }
    	if(B[19]^B[248]) { y[1] = (A[19]&A[248]^A[19]&B[19]^A[248]&B[19]^A[19]&B[248]^A[248]&B[248]^B[19]&B[248]^A[20]^A[248]^A[249]^B[19]^B[20]^B[249]); break; }
    	if(B[28]^B[248]) { y[1] = (A[28]&A[248]^A[28]&B[28]^A[248]&B[28]^A[28]&B[248]^A[248]&B[248]^B[28]&B[248]^A[29]^A[248]^A[249]^B[28]^B[29]^B[249]); break; }
    	if(B[37]^B[248]) { y[1] = (A[37]&A[248]^A[37]&B[37]^A[248]&B[37]^A[37]&B[248]^A[248]&B[248]^B[37]&B[248]^A[38]^A[248]^A[249]^B[37]^B[38]^B[249]); break; }
    	if(B[46]^B[248]) { y[1] = (A[46]&A[248]^A[46]&B[46]^A[248]&B[46]^A[46]&B[248]^A[248]&B[248]^B[46]&B[248]^A[47]^A[248]^A[249]^B[46]^B[47]^B[249]); break; }
    } while(0);
    
    do
    {
    	if(A[240]^1) { y[2] = (A[240]&B[240]^A[232]^A[241]^B[232]^B[240]^B[241]); break; }
    	if(B[2]^B[240]) { y[2] = (A[2]&A[240]^A[2]&B[2]^A[240]&B[2]^A[2]&B[240]^A[240]&B[240]^B[2]&B[240]^A[3]^A[240]^A[241]^B[2]^B[3]^B[241]); break; }
    	if(B[11]^B[240]) { y[2] = (A[11]&A[240]^A[11]&B[11]^A[240]&B[11]^A[11]&B[240]^A[240]&B[240]^B[11]&B[240]^A[12]^A[240]^A[241]^B[11]^B[12]^B[241]); break; }
    	if(B[20]^B[240]) { y[2] = (A[20]&A[240]^A[20]&B[20]^A[240]&B[20]^A[20]&B[240]^A[240]&B[240]^B[20]&B[240]^A[21]^A[240]^A[241]^B[20]^B[21]^B[241]); break; }
    	if(B[29]^B[240]) { y[2] = (A[29]&A[240]^A[29]&B[29]^A[240]&B[29]^A[29]&B[240]^A[240]&B[240]^B[29]&B[240]^A[30]^A[240]^A[241]^B[29]^B[30]^B[241]); break; }
    	if(B[38]^B[240]) { y[2] = (A[38]&A[240]^A[38]&B[38]^A[240]&B[38]^A[38]&B[240]^A[240]&B[240]^B[38]&B[240]^A[39]^A[240]^A[241]^B[38]^B[39]^B[241]); break; }
    	if(B[240]^B[249]) { y[2] = (A[240]&A[249]^A[240]&B[240]^A[249]&B[240]^A[240]&B[249]^A[249]&B[249]^B[240]&B[249]^A[240]^A[241]^A[250]^B[241]^B[249]^B[250]); break; }
    } while(0);
    
    do
    {
    	if(A[232]^1) { y[3] = (A[232]&B[232]^A[224]^A[233]^B[224]^B[232]^B[233]); break; }
    	if(B[3]^B[232]) { y[3] = (A[3]&A[232]^A[3]&B[3]^A[232]&B[3]^A[3]&B[232]^A[232]&B[232]^B[3]&B[232]^A[4]^A[232]^A[233]^B[3]^B[4]^B[233]); break; }
    	if(B[12]^B[232]) { y[3] = (A[12]&A[232]^A[12]&B[12]^A[232]&B[12]^A[12]&B[232]^A[232]&B[232]^B[12]&B[232]^A[13]^A[232]^A[233]^B[12]^B[13]^B[233]); break; }
    	if(B[21]^B[232]) { y[3] = (A[21]&A[232]^A[21]&B[21]^A[232]&B[21]^A[21]&B[232]^A[232]&B[232]^B[21]&B[232]^A[22]^A[232]^A[233]^B[21]^B[22]^B[233]); break; }
    	if(B[30]^B[232]) { y[3] = (A[30]&A[232]^A[30]&B[30]^A[232]&B[30]^A[30]&B[232]^A[232]&B[232]^B[30]&B[232]^A[31]^A[232]^A[233]^B[30]^B[31]^B[233]); break; }
    	if(B[232]^B[241]) { y[3] = (A[232]&A[241]^A[232]&B[232]^A[241]&B[232]^A[232]&B[241]^A[241]&B[241]^B[232]&B[241]^A[232]^A[233]^A[242]^B[233]^B[241]^B[242]); break; }
    	if(B[232]^B[250]) { y[3] = (A[232]&A[250]^A[232]&B[232]^A[250]&B[232]^A[232]&B[250]^A[250]&B[250]^B[232]&B[250]^A[232]^A[233]^A[251]^B[233]^B[250]^B[251]); break; }
    } while(0);
    
    do
    {
    	if(A[224]^1) { y[4] = (A[224]&B[224]^A[216]^A[225]^B[216]^B[224]^B[225]); break; }
    	if(B[4]^B[224]) { y[4] = (A[4]&A[224]^A[4]&B[4]^A[224]&B[4]^A[4]&B[224]^A[224]&B[224]^B[4]&B[224]^A[5]^A[224]^A[225]^B[4]^B[5]^B[225]); break; }
    	if(B[13]^B[224]) { y[4] = (A[13]&A[224]^A[13]&B[13]^A[224]&B[13]^A[13]&B[224]^A[224]&B[224]^B[13]&B[224]^A[14]^A[224]^A[225]^B[13]^B[14]^B[225]); break; }
    	if(B[22]^B[224]) { y[4] = (A[22]&A[224]^A[22]&B[22]^A[224]&B[22]^A[22]&B[224]^A[224]&B[224]^B[22]&B[224]^A[23]^A[224]^A[225]^B[22]^B[23]^B[225]); break; }
    	if(B[224]^B[233]) { y[4] = (A[224]&A[233]^A[224]&B[224]^A[233]&B[224]^A[224]&B[233]^A[233]&B[233]^B[224]&B[233]^A[224]^A[225]^A[234]^B[225]^B[233]^B[234]); break; }
    	if(B[224]^B[242]) { y[4] = (A[224]&A[242]^A[224]&B[224]^A[242]&B[224]^A[224]&B[242]^A[242]&B[242]^B[224]&B[242]^A[224]^A[225]^A[243]^B[225]^B[242]^B[243]); break; }
    	if(B[224]^B[251]) { y[4] = (A[224]&A[251]^A[224]&B[224]^A[251]&B[224]^A[224]&B[251]^A[251]&B[251]^B[224]&B[251]^A[224]^A[225]^A[252]^B[225]^B[251]^B[252]); break; }
    } while(0);
    
    do
    {
    	if(A[216]^1) { y[5] = (A[216]&B[216]^A[208]^A[217]^B[208]^B[216]^B[217]); break; }
    	if(B[5]^B[216]) { y[5] = (A[5]&A[216]^A[5]&B[5]^A[216]&B[5]^A[5]&B[216]^A[216]&B[216]^B[5]&B[216]^A[6]^A[216]^A[217]^B[5]^B[6]^B[217]); break; }
    	if(B[14]^B[216]) { y[5] = (A[14]&A[216]^A[14]&B[14]^A[216]&B[14]^A[14]&B[216]^A[216]&B[216]^B[14]&B[216]^A[15]^A[216]^A[217]^B[14]^B[15]^B[217]); break; }
    	if(B[216]^B[225]) { y[5] = (A[216]&A[225]^A[216]&B[216]^A[225]&B[216]^A[216]&B[225]^A[225]&B[225]^B[216]&B[225]^A[216]^A[217]^A[226]^B[217]^B[225]^B[226]); break; }
    	if(B[216]^B[234]) { y[5] = (A[216]&A[234]^A[216]&B[216]^A[234]&B[216]^A[216]&B[234]^A[234]&B[234]^B[216]&B[234]^A[216]^A[217]^A[235]^B[217]^B[234]^B[235]); break; }
    	if(B[216]^B[243]) { y[5] = (A[216]&A[243]^A[216]&B[216]^A[243]&B[216]^A[216]&B[243]^A[243]&B[243]^B[216]&B[243]^A[216]^A[217]^A[244]^B[217]^B[243]^B[244]); break; }
    	if(B[216]^B[252]) { y[5] = (A[216]&A[252]^A[216]&B[216]^A[252]&B[216]^A[216]&B[252]^A[252]&B[252]^B[216]&B[252]^A[216]^A[217]^A[253]^B[217]^B[252]^B[253]); break; }
    } while(0);
    
    do
    {
    	if(A[208]^1) { y[6] = (A[208]&B[208]^A[200]^A[209]^B[200]^B[208]^B[209]); break; }
    	if(B[6]^B[208]) { y[6] = (A[6]&A[208]^A[6]&B[6]^A[208]&B[6]^A[6]&B[208]^A[208]&B[208]^B[6]&B[208]^A[7]^A[208]^A[209]^B[6]^B[7]^B[209]); break; }
    	if(B[208]^B[217]) { y[6] = (A[208]&A[217]^A[208]&B[208]^A[217]&B[208]^A[208]&B[217]^A[217]&B[217]^B[208]&B[217]^A[208]^A[209]^A[218]^B[209]^B[217]^B[218]); break; }
    	if(B[208]^B[226]) { y[6] = (A[208]&A[226]^A[208]&B[208]^A[226]&B[208]^A[208]&B[226]^A[226]&B[226]^B[208]&B[226]^A[208]^A[209]^A[227]^B[209]^B[226]^B[227]); break; }
    	if(B[208]^B[235]) { y[6] = (A[208]&A[235]^A[208]&B[208]^A[235]&B[208]^A[208]&B[235]^A[235]&B[235]^B[208]&B[235]^A[208]^A[209]^A[236]^B[209]^B[235]^B[236]); break; }
    	if(B[208]^B[244]) { y[6] = (A[208]&A[244]^A[208]&B[208]^A[244]&B[208]^A[208]&B[244]^A[244]&B[244]^B[208]&B[244]^A[208]^A[209]^A[245]^B[209]^B[244]^B[245]); break; }
    	if(B[208]^B[253]) { y[6] = (A[208]&A[253]^A[208]&B[208]^A[253]&B[208]^A[208]&B[253]^A[253]&B[253]^B[208]&B[253]^A[208]^A[209]^A[254]^B[209]^B[253]^B[254]); break; }
    } while(0);
    
    do
    {
    	if(A[200]^1) { y[7] = (A[200]&B[200]^A[192]^A[201]^B[192]^B[200]^B[201]); break; }
    	if(B[200]^B[209]) { y[7] = (A[200]&A[209]^A[200]&B[200]^A[209]&B[200]^A[200]&B[209]^A[209]&B[209]^B[200]&B[209]^A[200]^A[201]^A[210]^B[201]^B[209]^B[210]); break; }
    	if(B[200]^B[218]) { y[7] = (A[200]&A[218]^A[200]&B[200]^A[218]&B[200]^A[200]&B[218]^A[218]&B[218]^B[200]&B[218]^A[200]^A[201]^A[219]^B[201]^B[218]^B[219]); break; }
    	if(B[200]^B[227]) { y[7] = (A[200]&A[227]^A[200]&B[200]^A[227]&B[200]^A[200]&B[227]^A[227]&B[227]^B[200]&B[227]^A[200]^A[201]^A[228]^B[201]^B[227]^B[228]); break; }
    	if(B[200]^B[236]) { y[7] = (A[200]&A[236]^A[200]&B[200]^A[236]&B[200]^A[200]&B[236]^A[236]&B[236]^B[200]&B[236]^A[200]^A[201]^A[237]^B[201]^B[236]^B[237]); break; }
    	if(B[200]^B[245]) { y[7] = (A[200]&A[245]^A[200]&B[200]^A[245]&B[200]^A[200]&B[245]^A[245]&B[245]^B[200]&B[245]^A[200]^A[201]^A[246]^B[201]^B[245]^B[246]); break; }
    	if(B[200]^B[254]) { y[7] = (A[200]&A[254]^A[200]&B[200]^A[254]&B[200]^A[200]&B[254]^A[254]&B[254]^B[200]&B[254]^A[200]^A[201]^A[255]^B[201]^B[254]^B[255]); break; }
    } while(0);
    
    do
    {
    	if(A[192]^1) { y[8] = (A[192]&B[192]^A[184]^A[193]^B[184]^B[192]^B[193]); break; }
    	if(B[192]^B[201]) { y[8] = (A[192]&A[201]^A[192]&B[192]^A[201]&B[192]^A[192]&B[201]^A[201]&B[201]^B[192]&B[201]^A[192]^A[193]^A[202]^B[193]^B[201]^B[202]); break; }
    	if(B[192]^B[210]) { y[8] = (A[192]&A[210]^A[192]&B[192]^A[210]&B[192]^A[192]&B[210]^A[210]&B[210]^B[192]&B[210]^A[192]^A[193]^A[211]^B[193]^B[210]^B[211]); break; }
    	if(B[192]^B[219]) { y[8] = (A[192]&A[219]^A[192]&B[192]^A[219]&B[192]^A[192]&B[219]^A[219]&B[219]^B[192]&B[219]^A[192]^A[193]^A[220]^B[193]^B[219]^B[220]); break; }
    	if(B[192]^B[228]) { y[8] = (A[192]&A[228]^A[192]&B[192]^A[228]&B[192]^A[192]&B[228]^A[228]&B[228]^B[192]&B[228]^A[192]^A[193]^A[229]^B[193]^B[228]^B[229]); break; }
    	if(B[192]^B[237]) { y[8] = (A[192]&A[237]^A[192]&B[192]^A[237]&B[192]^A[192]&B[237]^A[237]&B[237]^B[192]&B[237]^A[192]^A[193]^A[238]^B[193]^B[237]^B[238]); break; }
    	if(B[192]^B[246]) { y[8] = (A[192]&A[246]^A[192]&B[192]^A[246]&B[192]^A[192]&B[246]^A[246]&B[246]^B[192]&B[246]^A[192]^A[193]^A[247]^B[193]^B[246]^B[247]); break; }
    } while(0);
    
    do
    {
    	if(A[184]^1) { y[9] = (A[184]&B[184]^A[176]^A[185]^B[176]^B[184]^B[185]); break; }
    	if(B[184]^B[193]) { y[9] = (A[184]&A[193]^A[184]&B[184]^A[193]&B[184]^A[184]&B[193]^A[193]&B[193]^B[184]&B[193]^A[184]^A[185]^A[194]^B[185]^B[193]^B[194]); break; }
    	if(B[184]^B[202]) { y[9] = (A[184]&A[202]^A[184]&B[184]^A[202]&B[184]^A[184]&B[202]^A[202]&B[202]^B[184]&B[202]^A[184]^A[185]^A[203]^B[185]^B[202]^B[203]); break; }
    	if(B[184]^B[211]) { y[9] = (A[184]&A[211]^A[184]&B[184]^A[211]&B[184]^A[184]&B[211]^A[211]&B[211]^B[184]&B[211]^A[184]^A[185]^A[212]^B[185]^B[211]^B[212]); break; }
    	if(B[184]^B[220]) { y[9] = (A[184]&A[220]^A[184]&B[184]^A[220]&B[184]^A[184]&B[220]^A[220]&B[220]^B[184]&B[220]^A[184]^A[185]^A[221]^B[185]^B[220]^B[221]); break; }
    	if(B[184]^B[229]) { y[9] = (A[184]&A[229]^A[184]&B[184]^A[229]&B[184]^A[184]&B[229]^A[229]&B[229]^B[184]&B[229]^A[184]^A[185]^A[230]^B[185]^B[229]^B[230]); break; }
    	if(B[184]^B[238]) { y[9] = (A[184]&A[238]^A[184]&B[184]^A[238]&B[184]^A[184]&B[238]^A[238]&B[238]^B[184]&B[238]^A[184]^A[185]^A[239]^B[185]^B[238]^B[239]); break; }
    } while(0);
    
    do
    {
    	if(A[176]^1) { y[10] = (A[176]&B[176]^A[168]^A[177]^B[168]^B[176]^B[177]); break; }
    	if(B[176]^B[185]) { y[10] = (A[176]&A[185]^A[176]&B[176]^A[185]&B[176]^A[176]&B[185]^A[185]&B[185]^B[176]&B[185]^A[176]^A[177]^A[186]^B[177]^B[185]^B[186]); break; }
    	if(B[176]^B[194]) { y[10] = (A[176]&A[194]^A[176]&B[176]^A[194]&B[176]^A[176]&B[194]^A[194]&B[194]^B[176]&B[194]^A[176]^A[177]^A[195]^B[177]^B[194]^B[195]); break; }
    	if(B[176]^B[203]) { y[10] = (A[176]&A[203]^A[176]&B[176]^A[203]&B[176]^A[176]&B[203]^A[203]&B[203]^B[176]&B[203]^A[176]^A[177]^A[204]^B[177]^B[203]^B[204]); break; }
    	if(B[176]^B[212]) { y[10] = (A[176]&A[212]^A[176]&B[176]^A[212]&B[176]^A[176]&B[212]^A[212]&B[212]^B[176]&B[212]^A[176]^A[177]^A[213]^B[177]^B[212]^B[213]); break; }
    	if(B[176]^B[221]) { y[10] = (A[176]&A[221]^A[176]&B[176]^A[221]&B[176]^A[176]&B[221]^A[221]&B[221]^B[176]&B[221]^A[176]^A[177]^A[222]^B[177]^B[221]^B[222]); break; }
    	if(B[176]^B[230]) { y[10] = (A[176]&A[230]^A[176]&B[176]^A[230]&B[176]^A[176]&B[230]^A[230]&B[230]^B[176]&B[230]^A[176]^A[177]^A[231]^B[177]^B[230]^B[231]); break; }
    } while(0);
    
    do
    {
    	if(A[168]^1) { y[11] = (A[168]&B[168]^A[160]^A[169]^B[160]^B[168]^B[169]); break; }
    	if(B[168]^B[177]) { y[11] = (A[168]&A[177]^A[168]&B[168]^A[177]&B[168]^A[168]&B[177]^A[177]&B[177]^B[168]&B[177]^A[168]^A[169]^A[178]^B[169]^B[177]^B[178]); break; }
    	if(B[168]^B[186]) { y[11] = (A[168]&A[186]^A[168]&B[168]^A[186]&B[168]^A[168]&B[186]^A[186]&B[186]^B[168]&B[186]^A[168]^A[169]^A[187]^B[169]^B[186]^B[187]); break; }
    	if(B[168]^B[195]) { y[11] = (A[168]&A[195]^A[168]&B[168]^A[195]&B[168]^A[168]&B[195]^A[195]&B[195]^B[168]&B[195]^A[168]^A[169]^A[196]^B[169]^B[195]^B[196]); break; }
    	if(B[168]^B[204]) { y[11] = (A[168]&A[204]^A[168]&B[168]^A[204]&B[168]^A[168]&B[204]^A[204]&B[204]^B[168]&B[204]^A[168]^A[169]^A[205]^B[169]^B[204]^B[205]); break; }
    	if(B[168]^B[213]) { y[11] = (A[168]&A[213]^A[168]&B[168]^A[213]&B[168]^A[168]&B[213]^A[213]&B[213]^B[168]&B[213]^A[168]^A[169]^A[214]^B[169]^B[213]^B[214]); break; }
    	if(B[168]^B[222]) { y[11] = (A[168]&A[222]^A[168]&B[168]^A[222]&B[168]^A[168]&B[222]^A[222]&B[222]^B[168]&B[222]^A[168]^A[169]^A[223]^B[169]^B[222]^B[223]); break; }
    } while(0);
    
    do
    {
    	if(A[160]^1) { y[12] = (A[160]&B[160]^A[152]^A[161]^B[152]^B[160]^B[161]); break; }
    	if(B[160]^B[169]) { y[12] = (A[160]&A[169]^A[160]&B[160]^A[169]&B[160]^A[160]&B[169]^A[169]&B[169]^B[160]&B[169]^A[160]^A[161]^A[170]^B[161]^B[169]^B[170]); break; }
    	if(B[160]^B[178]) { y[12] = (A[160]&A[178]^A[160]&B[160]^A[178]&B[160]^A[160]&B[178]^A[178]&B[178]^B[160]&B[178]^A[160]^A[161]^A[179]^B[161]^B[178]^B[179]); break; }
    	if(B[160]^B[187]) { y[12] = (A[160]&A[187]^A[160]&B[160]^A[187]&B[160]^A[160]&B[187]^A[187]&B[187]^B[160]&B[187]^A[160]^A[161]^A[188]^B[161]^B[187]^B[188]); break; }
    	if(B[160]^B[196]) { y[12] = (A[160]&A[196]^A[160]&B[160]^A[196]&B[160]^A[160]&B[196]^A[196]&B[196]^B[160]&B[196]^A[160]^A[161]^A[197]^B[161]^B[196]^B[197]); break; }
    	if(B[160]^B[205]) { y[12] = (A[160]&A[205]^A[160]&B[160]^A[205]&B[160]^A[160]&B[205]^A[205]&B[205]^B[160]&B[205]^A[160]^A[161]^A[206]^B[161]^B[205]^B[206]); break; }
    	if(B[160]^B[214]) { y[12] = (A[160]&A[214]^A[160]&B[160]^A[214]&B[160]^A[160]&B[214]^A[214]&B[214]^B[160]&B[214]^A[160]^A[161]^A[215]^B[161]^B[214]^B[215]); break; }
    } while(0);
    
    do
    {
    	if(A[152]^1) { y[13] = (A[152]&B[152]^A[144]^A[153]^B[144]^B[152]^B[153]); break; }
    	if(B[152]^B[161]) { y[13] = (A[152]&A[161]^A[152]&B[152]^A[161]&B[152]^A[152]&B[161]^A[161]&B[161]^B[152]&B[161]^A[152]^A[153]^A[162]^B[153]^B[161]^B[162]); break; }
    	if(B[152]^B[170]) { y[13] = (A[152]&A[170]^A[152]&B[152]^A[170]&B[152]^A[152]&B[170]^A[170]&B[170]^B[152]&B[170]^A[152]^A[153]^A[171]^B[153]^B[170]^B[171]); break; }
    	if(B[152]^B[179]) { y[13] = (A[152]&A[179]^A[152]&B[152]^A[179]&B[152]^A[152]&B[179]^A[179]&B[179]^B[152]&B[179]^A[152]^A[153]^A[180]^B[153]^B[179]^B[180]); break; }
    	if(B[152]^B[188]) { y[13] = (A[152]&A[188]^A[152]&B[152]^A[188]&B[152]^A[152]&B[188]^A[188]&B[188]^B[152]&B[188]^A[152]^A[153]^A[189]^B[153]^B[188]^B[189]); break; }
    	if(B[152]^B[197]) { y[13] = (A[152]&A[197]^A[152]&B[152]^A[197]&B[152]^A[152]&B[197]^A[197]&B[197]^B[152]&B[197]^A[152]^A[153]^A[198]^B[153]^B[197]^B[198]); break; }
    	if(B[152]^B[206]) { y[13] = (A[152]&A[206]^A[152]&B[152]^A[206]&B[152]^A[152]&B[206]^A[206]&B[206]^B[152]&B[206]^A[152]^A[153]^A[207]^B[153]^B[206]^B[207]); break; }
    } while(0);
    
    do
    {
    	if(A[144]^1) { y[14] = (A[144]&B[144]^A[136]^A[145]^B[136]^B[144]^B[145]); break; }
    	if(B[144]^B[153]) { y[14] = (A[144]&A[153]^A[144]&B[144]^A[153]&B[144]^A[144]&B[153]^A[153]&B[153]^B[144]&B[153]^A[144]^A[145]^A[154]^B[145]^B[153]^B[154]); break; }
    	if(B[144]^B[162]) { y[14] = (A[144]&A[162]^A[144]&B[144]^A[162]&B[144]^A[144]&B[162]^A[162]&B[162]^B[144]&B[162]^A[144]^A[145]^A[163]^B[145]^B[162]^B[163]); break; }
    	if(B[144]^B[171]) { y[14] = (A[144]&A[171]^A[144]&B[144]^A[171]&B[144]^A[144]&B[171]^A[171]&B[171]^B[144]&B[171]^A[144]^A[145]^A[172]^B[145]^B[171]^B[172]); break; }
    	if(B[144]^B[180]) { y[14] = (A[144]&A[180]^A[144]&B[144]^A[180]&B[144]^A[144]&B[180]^A[180]&B[180]^B[144]&B[180]^A[144]^A[145]^A[181]^B[145]^B[180]^B[181]); break; }
    	if(B[144]^B[189]) { y[14] = (A[144]&A[189]^A[144]&B[144]^A[189]&B[144]^A[144]&B[189]^A[189]&B[189]^B[144]&B[189]^A[144]^A[145]^A[190]^B[145]^B[189]^B[190]); break; }
    	if(B[144]^B[198]) { y[14] = (A[144]&A[198]^A[144]&B[144]^A[198]&B[144]^A[144]&B[198]^A[198]&B[198]^B[144]&B[198]^A[144]^A[145]^A[199]^B[145]^B[198]^B[199]); break; }
    } while(0);
    
    do
    {
    	if(A[136]^1) { y[15] = (A[136]&B[136]^A[128]^A[137]^B[128]^B[136]^B[137]); break; }
    	if(B[136]^B[145]) { y[15] = (A[136]&A[145]^A[136]&B[136]^A[145]&B[136]^A[136]&B[145]^A[145]&B[145]^B[136]&B[145]^A[136]^A[137]^A[146]^B[137]^B[145]^B[146]); break; }
    	if(B[136]^B[154]) { y[15] = (A[136]&A[154]^A[136]&B[136]^A[154]&B[136]^A[136]&B[154]^A[154]&B[154]^B[136]&B[154]^A[136]^A[137]^A[155]^B[137]^B[154]^B[155]); break; }
    	if(B[136]^B[163]) { y[15] = (A[136]&A[163]^A[136]&B[136]^A[163]&B[136]^A[136]&B[163]^A[163]&B[163]^B[136]&B[163]^A[136]^A[137]^A[164]^B[137]^B[163]^B[164]); break; }
    	if(B[136]^B[172]) { y[15] = (A[136]&A[172]^A[136]&B[136]^A[172]&B[136]^A[136]&B[172]^A[172]&B[172]^B[136]&B[172]^A[136]^A[137]^A[173]^B[137]^B[172]^B[173]); break; }
    	if(B[136]^B[181]) { y[15] = (A[136]&A[181]^A[136]&B[136]^A[181]&B[136]^A[136]&B[181]^A[181]&B[181]^B[136]&B[181]^A[136]^A[137]^A[182]^B[137]^B[181]^B[182]); break; }
    	if(B[136]^B[190]) { y[15] = (A[136]&A[190]^A[136]&B[136]^A[190]&B[136]^A[136]&B[190]^A[190]&B[190]^B[136]&B[190]^A[136]^A[137]^A[191]^B[137]^B[190]^B[191]); break; }
    } while(0);
    
    do
    {
    	if(A[128]^1) { y[16] = (A[128]&B[128]^A[120]^A[129]^B[120]^B[128]^B[129]); break; }
    	if(B[128]^B[137]) { y[16] = (A[128]&A[137]^A[128]&B[128]^A[137]&B[128]^A[128]&B[137]^A[137]&B[137]^B[128]&B[137]^A[128]^A[129]^A[138]^B[129]^B[137]^B[138]); break; }
    	if(B[128]^B[146]) { y[16] = (A[128]&A[146]^A[128]&B[128]^A[146]&B[128]^A[128]&B[146]^A[146]&B[146]^B[128]&B[146]^A[128]^A[129]^A[147]^B[129]^B[146]^B[147]); break; }
    	if(B[128]^B[155]) { y[16] = (A[128]&A[155]^A[128]&B[128]^A[155]&B[128]^A[128]&B[155]^A[155]&B[155]^B[128]&B[155]^A[128]^A[129]^A[156]^B[129]^B[155]^B[156]); break; }
    	if(B[128]^B[164]) { y[16] = (A[128]&A[164]^A[128]&B[128]^A[164]&B[128]^A[128]&B[164]^A[164]&B[164]^B[128]&B[164]^A[128]^A[129]^A[165]^B[129]^B[164]^B[165]); break; }
    	if(B[128]^B[173]) { y[16] = (A[128]&A[173]^A[128]&B[128]^A[173]&B[128]^A[128]&B[173]^A[173]&B[173]^B[128]&B[173]^A[128]^A[129]^A[174]^B[129]^B[173]^B[174]); break; }
    	if(B[128]^B[182]) { y[16] = (A[128]&A[182]^A[128]&B[128]^A[182]&B[128]^A[128]&B[182]^A[182]&B[182]^B[128]&B[182]^A[128]^A[129]^A[183]^B[129]^B[182]^B[183]); break; }
    } while(0);
    
    do
    {
    	if(A[120]^1) { y[17] = (A[120]&B[120]^A[112]^A[121]^B[112]^B[120]^B[121]); break; }
    	if(B[120]^B[129]) { y[17] = (A[120]&A[129]^A[120]&B[120]^A[129]&B[120]^A[120]&B[129]^A[129]&B[129]^B[120]&B[129]^A[120]^A[121]^A[130]^B[121]^B[129]^B[130]); break; }
    	if(B[120]^B[138]) { y[17] = (A[120]&A[138]^A[120]&B[120]^A[138]&B[120]^A[120]&B[138]^A[138]&B[138]^B[120]&B[138]^A[120]^A[121]^A[139]^B[121]^B[138]^B[139]); break; }
    	if(B[120]^B[147]) { y[17] = (A[120]&A[147]^A[120]&B[120]^A[147]&B[120]^A[120]&B[147]^A[147]&B[147]^B[120]&B[147]^A[120]^A[121]^A[148]^B[121]^B[147]^B[148]); break; }
    	if(B[120]^B[156]) { y[17] = (A[120]&A[156]^A[120]&B[120]^A[156]&B[120]^A[120]&B[156]^A[156]&B[156]^B[120]&B[156]^A[120]^A[121]^A[157]^B[121]^B[156]^B[157]); break; }
    	if(B[120]^B[165]) { y[17] = (A[120]&A[165]^A[120]&B[120]^A[165]&B[120]^A[120]&B[165]^A[165]&B[165]^B[120]&B[165]^A[120]^A[121]^A[166]^B[121]^B[165]^B[166]); break; }
    	if(B[120]^B[174]) { y[17] = (A[120]&A[174]^A[120]&B[120]^A[174]&B[120]^A[120]&B[174]^A[174]&B[174]^B[120]&B[174]^A[120]^A[121]^A[175]^B[121]^B[174]^B[175]); break; }
    } while(0);
    
    do
    {
    	if(A[112]^1) { y[18] = (A[112]&B[112]^A[104]^A[113]^B[104]^B[112]^B[113]); break; }
    	if(B[112]^B[121]) { y[18] = (A[112]&A[121]^A[112]&B[112]^A[121]&B[112]^A[112]&B[121]^A[121]&B[121]^B[112]&B[121]^A[112]^A[113]^A[122]^B[113]^B[121]^B[122]); break; }
    	if(B[112]^B[130]) { y[18] = (A[112]&A[130]^A[112]&B[112]^A[130]&B[112]^A[112]&B[130]^A[130]&B[130]^B[112]&B[130]^A[112]^A[113]^A[131]^B[113]^B[130]^B[131]); break; }
    	if(B[112]^B[139]) { y[18] = (A[112]&A[139]^A[112]&B[112]^A[139]&B[112]^A[112]&B[139]^A[139]&B[139]^B[112]&B[139]^A[112]^A[113]^A[140]^B[113]^B[139]^B[140]); break; }
    	if(B[112]^B[148]) { y[18] = (A[112]&A[148]^A[112]&B[112]^A[148]&B[112]^A[112]&B[148]^A[148]&B[148]^B[112]&B[148]^A[112]^A[113]^A[149]^B[113]^B[148]^B[149]); break; }
    	if(B[112]^B[157]) { y[18] = (A[112]&A[157]^A[112]&B[112]^A[157]&B[112]^A[112]&B[157]^A[157]&B[157]^B[112]&B[157]^A[112]^A[113]^A[158]^B[113]^B[157]^B[158]); break; }
    	if(B[112]^B[166]) { y[18] = (A[112]&A[166]^A[112]&B[112]^A[166]&B[112]^A[112]&B[166]^A[166]&B[166]^B[112]&B[166]^A[112]^A[113]^A[167]^B[113]^B[166]^B[167]); break; }
    } while(0);
    
    do
    {
    	if(A[104]^1) { y[19] = (A[104]&B[104]^A[96]^A[105]^B[96]^B[104]^B[105]); break; }
    	if(B[104]^B[113]) { y[19] = (A[104]&A[113]^A[104]&B[104]^A[113]&B[104]^A[104]&B[113]^A[113]&B[113]^B[104]&B[113]^A[104]^A[105]^A[114]^B[105]^B[113]^B[114]); break; }
    	if(B[104]^B[122]) { y[19] = (A[104]&A[122]^A[104]&B[104]^A[122]&B[104]^A[104]&B[122]^A[122]&B[122]^B[104]&B[122]^A[104]^A[105]^A[123]^B[105]^B[122]^B[123]); break; }
    	if(B[104]^B[131]) { y[19] = (A[104]&A[131]^A[104]&B[104]^A[131]&B[104]^A[104]&B[131]^A[131]&B[131]^B[104]&B[131]^A[104]^A[105]^A[132]^B[105]^B[131]^B[132]); break; }
    	if(B[104]^B[140]) { y[19] = (A[104]&A[140]^A[104]&B[104]^A[140]&B[104]^A[104]&B[140]^A[140]&B[140]^B[104]&B[140]^A[104]^A[105]^A[141]^B[105]^B[140]^B[141]); break; }
    	if(B[104]^B[149]) { y[19] = (A[104]&A[149]^A[104]&B[104]^A[149]&B[104]^A[104]&B[149]^A[149]&B[149]^B[104]&B[149]^A[104]^A[105]^A[150]^B[105]^B[149]^B[150]); break; }
    	if(B[104]^B[158]) { y[19] = (A[104]&A[158]^A[104]&B[104]^A[158]&B[104]^A[104]&B[158]^A[158]&B[158]^B[104]&B[158]^A[104]^A[105]^A[159]^B[105]^B[158]^B[159]); break; }
    } while(0);
    
    do
    {
    	if(A[96]^1) { y[20] = (A[96]&B[96]^A[88]^A[97]^B[88]^B[96]^B[97]); break; }
    	if(B[96]^B[105]) { y[20] = (A[96]&A[105]^A[96]&B[96]^A[105]&B[96]^A[96]&B[105]^A[105]&B[105]^B[96]&B[105]^A[96]^A[97]^A[106]^B[97]^B[105]^B[106]); break; }
    	if(B[96]^B[114]) { y[20] = (A[96]&A[114]^A[96]&B[96]^A[114]&B[96]^A[96]&B[114]^A[114]&B[114]^B[96]&B[114]^A[96]^A[97]^A[115]^B[97]^B[114]^B[115]); break; }
    	if(B[96]^B[123]) { y[20] = (A[96]&A[123]^A[96]&B[96]^A[123]&B[96]^A[96]&B[123]^A[123]&B[123]^B[96]&B[123]^A[96]^A[97]^A[124]^B[97]^B[123]^B[124]); break; }
    	if(B[96]^B[132]) { y[20] = (A[96]&A[132]^A[96]&B[96]^A[132]&B[96]^A[96]&B[132]^A[132]&B[132]^B[96]&B[132]^A[96]^A[97]^A[133]^B[97]^B[132]^B[133]); break; }
    	if(B[96]^B[141]) { y[20] = (A[96]&A[141]^A[96]&B[96]^A[141]&B[96]^A[96]&B[141]^A[141]&B[141]^B[96]&B[141]^A[96]^A[97]^A[142]^B[97]^B[141]^B[142]); break; }
    	if(B[96]^B[150]) { y[20] = (A[96]&A[150]^A[96]&B[96]^A[150]&B[96]^A[96]&B[150]^A[150]&B[150]^B[96]&B[150]^A[96]^A[97]^A[151]^B[97]^B[150]^B[151]); break; }
    } while(0);
    
    do
    {
    	if(A[88]^1) { y[21] = (A[88]&B[88]^A[80]^A[89]^B[80]^B[88]^B[89]); break; }
    	if(B[88]^B[97]) { y[21] = (A[88]&A[97]^A[88]&B[88]^A[97]&B[88]^A[88]&B[97]^A[97]&B[97]^B[88]&B[97]^A[88]^A[89]^A[98]^B[89]^B[97]^B[98]); break; }
    	if(B[88]^B[106]) { y[21] = (A[88]&A[106]^A[88]&B[88]^A[106]&B[88]^A[88]&B[106]^A[106]&B[106]^B[88]&B[106]^A[88]^A[89]^A[107]^B[89]^B[106]^B[107]); break; }
    	if(B[88]^B[115]) { y[21] = (A[88]&A[115]^A[88]&B[88]^A[115]&B[88]^A[88]&B[115]^A[115]&B[115]^B[88]&B[115]^A[88]^A[89]^A[116]^B[89]^B[115]^B[116]); break; }
    	if(B[88]^B[124]) { y[21] = (A[88]&A[124]^A[88]&B[88]^A[124]&B[88]^A[88]&B[124]^A[124]&B[124]^B[88]&B[124]^A[88]^A[89]^A[125]^B[89]^B[124]^B[125]); break; }
    	if(B[88]^B[133]) { y[21] = (A[88]&A[133]^A[88]&B[88]^A[133]&B[88]^A[88]&B[133]^A[133]&B[133]^B[88]&B[133]^A[88]^A[89]^A[134]^B[89]^B[133]^B[134]); break; }
    	if(B[88]^B[142]) { y[21] = (A[88]&A[142]^A[88]&B[88]^A[142]&B[88]^A[88]&B[142]^A[142]&B[142]^B[88]&B[142]^A[88]^A[89]^A[143]^B[89]^B[142]^B[143]); break; }
    } while(0);
    
    do
    {
    	if(A[80]^1) { y[22] = (A[80]&B[80]^A[72]^A[81]^B[72]^B[80]^B[81]); break; }
    	if(B[80]^B[89]) { y[22] = (A[80]&A[89]^A[80]&B[80]^A[89]&B[80]^A[80]&B[89]^A[89]&B[89]^B[80]&B[89]^A[80]^A[81]^A[90]^B[81]^B[89]^B[90]); break; }
    	if(B[80]^B[98]) { y[22] = (A[80]&A[98]^A[80]&B[80]^A[98]&B[80]^A[80]&B[98]^A[98]&B[98]^B[80]&B[98]^A[80]^A[81]^A[99]^B[81]^B[98]^B[99]); break; }
    	if(B[80]^B[107]) { y[22] = (A[80]&A[107]^A[80]&B[80]^A[107]&B[80]^A[80]&B[107]^A[107]&B[107]^B[80]&B[107]^A[80]^A[81]^A[108]^B[81]^B[107]^B[108]); break; }
    	if(B[80]^B[116]) { y[22] = (A[80]&A[116]^A[80]&B[80]^A[116]&B[80]^A[80]&B[116]^A[116]&B[116]^B[80]&B[116]^A[80]^A[81]^A[117]^B[81]^B[116]^B[117]); break; }
    	if(B[80]^B[125]) { y[22] = (A[80]&A[125]^A[80]&B[80]^A[125]&B[80]^A[80]&B[125]^A[125]&B[125]^B[80]&B[125]^A[80]^A[81]^A[126]^B[81]^B[125]^B[126]); break; }
    	if(B[80]^B[134]) { y[22] = (A[80]&A[134]^A[80]&B[80]^A[134]&B[80]^A[80]&B[134]^A[134]&B[134]^B[80]&B[134]^A[80]^A[81]^A[135]^B[81]^B[134]^B[135]); break; }
    } while(0);
    
    do
    {
    	if(A[72]^1) { y[23] = (A[72]&B[72]^A[64]^A[73]^B[64]^B[72]^B[73]); break; }
    	if(B[72]^B[81]) { y[23] = (A[72]&A[81]^A[72]&B[72]^A[81]&B[72]^A[72]&B[81]^A[81]&B[81]^B[72]&B[81]^A[72]^A[73]^A[82]^B[73]^B[81]^B[82]); break; }
    	if(B[72]^B[90]) { y[23] = (A[72]&A[90]^A[72]&B[72]^A[90]&B[72]^A[72]&B[90]^A[90]&B[90]^B[72]&B[90]^A[72]^A[73]^A[91]^B[73]^B[90]^B[91]); break; }
    	if(B[72]^B[99]) { y[23] = (A[72]&A[99]^A[72]&B[72]^A[99]&B[72]^A[72]&B[99]^A[99]&B[99]^B[72]&B[99]^A[72]^A[73]^A[100]^B[73]^B[99]^B[100]); break; }
    	if(B[72]^B[108]) { y[23] = (A[72]&A[108]^A[72]&B[72]^A[108]&B[72]^A[72]&B[108]^A[108]&B[108]^B[72]&B[108]^A[72]^A[73]^A[109]^B[73]^B[108]^B[109]); break; }
    	if(B[72]^B[117]) { y[23] = (A[72]&A[117]^A[72]&B[72]^A[117]&B[72]^A[72]&B[117]^A[117]&B[117]^B[72]&B[117]^A[72]^A[73]^A[118]^B[73]^B[117]^B[118]); break; }
    	if(B[72]^B[126]) { y[23] = (A[72]&A[126]^A[72]&B[72]^A[126]&B[72]^A[72]&B[126]^A[126]&B[126]^B[72]&B[126]^A[72]^A[73]^A[127]^B[73]^B[126]^B[127]); break; }
    } while(0);
    
    do
    {
    	if(A[64]^1) { y[24] = (A[64]&B[64]^A[56]^A[65]^B[56]^B[64]^B[65]); break; }
    	if(B[64]^B[73]) { y[24] = (A[64]&A[73]^A[64]&B[64]^A[73]&B[64]^A[64]&B[73]^A[73]&B[73]^B[64]&B[73]^A[64]^A[65]^A[74]^B[65]^B[73]^B[74]); break; }
    	if(B[64]^B[82]) { y[24] = (A[64]&A[82]^A[64]&B[64]^A[82]&B[64]^A[64]&B[82]^A[82]&B[82]^B[64]&B[82]^A[64]^A[65]^A[83]^B[65]^B[82]^B[83]); break; }
    	if(B[64]^B[91]) { y[24] = (A[64]&A[91]^A[64]&B[64]^A[91]&B[64]^A[64]&B[91]^A[91]&B[91]^B[64]&B[91]^A[64]^A[65]^A[92]^B[65]^B[91]^B[92]); break; }
    	if(B[64]^B[100]) { y[24] = (A[64]&A[100]^A[64]&B[64]^A[100]&B[64]^A[64]&B[100]^A[100]&B[100]^B[64]&B[100]^A[64]^A[65]^A[101]^B[65]^B[100]^B[101]); break; }
    	if(B[64]^B[109]) { y[24] = (A[64]&A[109]^A[64]&B[64]^A[109]&B[64]^A[64]&B[109]^A[109]&B[109]^B[64]&B[109]^A[64]^A[65]^A[110]^B[65]^B[109]^B[110]); break; }
    	if(B[64]^B[118]) { y[24] = (A[64]&A[118]^A[64]&B[64]^A[118]&B[64]^A[64]&B[118]^A[118]&B[118]^B[64]&B[118]^A[64]^A[65]^A[119]^B[65]^B[118]^B[119]); break; }
    } while(0);
    
    do
    {
    	if(A[56]^1) { y[25] = (A[56]&B[56]^A[48]^A[57]^B[48]^B[56]^B[57]); break; }
    	if(B[56]^B[65]) { y[25] = (A[56]&A[65]^A[56]&B[56]^A[65]&B[56]^A[56]&B[65]^A[65]&B[65]^B[56]&B[65]^A[56]^A[57]^A[66]^B[57]^B[65]^B[66]); break; }
    	if(B[56]^B[74]) { y[25] = (A[56]&A[74]^A[56]&B[56]^A[74]&B[56]^A[56]&B[74]^A[74]&B[74]^B[56]&B[74]^A[56]^A[57]^A[75]^B[57]^B[74]^B[75]); break; }
    	if(B[56]^B[83]) { y[25] = (A[56]&A[83]^A[56]&B[56]^A[83]&B[56]^A[56]&B[83]^A[83]&B[83]^B[56]&B[83]^A[56]^A[57]^A[84]^B[57]^B[83]^B[84]); break; }
    	if(B[56]^B[92]) { y[25] = (A[56]&A[92]^A[56]&B[56]^A[92]&B[56]^A[56]&B[92]^A[92]&B[92]^B[56]&B[92]^A[56]^A[57]^A[93]^B[57]^B[92]^B[93]); break; }
    	if(B[56]^B[101]) { y[25] = (A[56]&A[101]^A[56]&B[56]^A[101]&B[56]^A[56]&B[101]^A[101]&B[101]^B[56]&B[101]^A[56]^A[57]^A[102]^B[57]^B[101]^B[102]); break; }
    	if(B[56]^B[110]) { y[25] = (A[56]&A[110]^A[56]&B[56]^A[110]&B[56]^A[56]&B[110]^A[110]&B[110]^B[56]&B[110]^A[56]^A[57]^A[111]^B[57]^B[110]^B[111]); break; }
    } while(0);
    
    do
    {
    	if(A[48]^1) { y[26] = (A[48]&B[48]^A[40]^A[49]^B[40]^B[48]^B[49]); break; }
    	if(B[48]^B[57]) { y[26] = (A[48]&A[57]^A[48]&B[48]^A[57]&B[48]^A[48]&B[57]^A[57]&B[57]^B[48]&B[57]^A[48]^A[49]^A[58]^B[49]^B[57]^B[58]); break; }
    	if(B[48]^B[66]) { y[26] = (A[48]&A[66]^A[48]&B[48]^A[66]&B[48]^A[48]&B[66]^A[66]&B[66]^B[48]&B[66]^A[48]^A[49]^A[67]^B[49]^B[66]^B[67]); break; }
    	if(B[48]^B[75]) { y[26] = (A[48]&A[75]^A[48]&B[48]^A[75]&B[48]^A[48]&B[75]^A[75]&B[75]^B[48]&B[75]^A[48]^A[49]^A[76]^B[49]^B[75]^B[76]); break; }
    	if(B[48]^B[84]) { y[26] = (A[48]&A[84]^A[48]&B[48]^A[84]&B[48]^A[48]&B[84]^A[84]&B[84]^B[48]&B[84]^A[48]^A[49]^A[85]^B[49]^B[84]^B[85]); break; }
    	if(B[48]^B[93]) { y[26] = (A[48]&A[93]^A[48]&B[48]^A[93]&B[48]^A[48]&B[93]^A[93]&B[93]^B[48]&B[93]^A[48]^A[49]^A[94]^B[49]^B[93]^B[94]); break; }
    	if(B[48]^B[102]) { y[26] = (A[48]&A[102]^A[48]&B[48]^A[102]&B[48]^A[48]&B[102]^A[102]&B[102]^B[48]&B[102]^A[48]^A[49]^A[103]^B[49]^B[102]^B[103]); break; }
    } while(0);
    
    do
    {
    	if(A[40]^1) { y[27] = (A[40]&B[40]^A[32]^A[41]^B[32]^B[40]^B[41]); break; }
    	if(B[40]^B[49]) { y[27] = (A[40]&A[49]^A[40]&B[40]^A[49]&B[40]^A[40]&B[49]^A[49]&B[49]^B[40]&B[49]^A[40]^A[41]^A[50]^B[41]^B[49]^B[50]); break; }
    	if(B[40]^B[58]) { y[27] = (A[40]&A[58]^A[40]&B[40]^A[58]&B[40]^A[40]&B[58]^A[58]&B[58]^B[40]&B[58]^A[40]^A[41]^A[59]^B[41]^B[58]^B[59]); break; }
    	if(B[40]^B[67]) { y[27] = (A[40]&A[67]^A[40]&B[40]^A[67]&B[40]^A[40]&B[67]^A[67]&B[67]^B[40]&B[67]^A[40]^A[41]^A[68]^B[41]^B[67]^B[68]); break; }
    	if(B[40]^B[76]) { y[27] = (A[40]&A[76]^A[40]&B[40]^A[76]&B[40]^A[40]&B[76]^A[76]&B[76]^B[40]&B[76]^A[40]^A[41]^A[77]^B[41]^B[76]^B[77]); break; }
    	if(B[40]^B[85]) { y[27] = (A[40]&A[85]^A[40]&B[40]^A[85]&B[40]^A[40]&B[85]^A[85]&B[85]^B[40]&B[85]^A[40]^A[41]^A[86]^B[41]^B[85]^B[86]); break; }
    	if(B[40]^B[94]) { y[27] = (A[40]&A[94]^A[40]&B[40]^A[94]&B[40]^A[40]&B[94]^A[94]&B[94]^B[40]&B[94]^A[40]^A[41]^A[95]^B[41]^B[94]^B[95]); break; }
    } while(0);
    
    do
    {
    	if(A[32]^1) { y[28] = (A[32]&B[32]^A[24]^A[33]^B[24]^B[32]^B[33]); break; }
    	if(B[32]^B[41]) { y[28] = (A[32]&A[41]^A[32]&B[32]^A[41]&B[32]^A[32]&B[41]^A[41]&B[41]^B[32]&B[41]^A[32]^A[33]^A[42]^B[33]^B[41]^B[42]); break; }
    	if(B[32]^B[50]) { y[28] = (A[32]&A[50]^A[32]&B[32]^A[50]&B[32]^A[32]&B[50]^A[50]&B[50]^B[32]&B[50]^A[32]^A[33]^A[51]^B[33]^B[50]^B[51]); break; }
    	if(B[32]^B[59]) { y[28] = (A[32]&A[59]^A[32]&B[32]^A[59]&B[32]^A[32]&B[59]^A[59]&B[59]^B[32]&B[59]^A[32]^A[33]^A[60]^B[33]^B[59]^B[60]); break; }
    	if(B[32]^B[68]) { y[28] = (A[32]&A[68]^A[32]&B[32]^A[68]&B[32]^A[32]&B[68]^A[68]&B[68]^B[32]&B[68]^A[32]^A[33]^A[69]^B[33]^B[68]^B[69]); break; }
    	if(B[32]^B[77]) { y[28] = (A[32]&A[77]^A[32]&B[32]^A[77]&B[32]^A[32]&B[77]^A[77]&B[77]^B[32]&B[77]^A[32]^A[33]^A[78]^B[33]^B[77]^B[78]); break; }
    	if(B[32]^B[86]) { y[28] = (A[32]&A[86]^A[32]&B[32]^A[86]&B[32]^A[32]&B[86]^A[86]&B[86]^B[32]&B[86]^A[32]^A[33]^A[87]^B[33]^B[86]^B[87]); break; }
    } while(0);
    
    do
    {
    	if(A[24]^1) { y[29] = (A[24]&B[24]^A[16]^A[25]^B[16]^B[24]^B[25]); break; }
    	if(B[24]^B[33]) { y[29] = (A[24]&A[33]^A[24]&B[24]^A[33]&B[24]^A[24]&B[33]^A[33]&B[33]^B[24]&B[33]^A[24]^A[25]^A[34]^B[25]^B[33]^B[34]); break; }
    	if(B[24]^B[42]) { y[29] = (A[24]&A[42]^A[24]&B[24]^A[42]&B[24]^A[24]&B[42]^A[42]&B[42]^B[24]&B[42]^A[24]^A[25]^A[43]^B[25]^B[42]^B[43]); break; }
    	if(B[24]^B[51]) { y[29] = (A[24]&A[51]^A[24]&B[24]^A[51]&B[24]^A[24]&B[51]^A[51]&B[51]^B[24]&B[51]^A[24]^A[25]^A[52]^B[25]^B[51]^B[52]); break; }
    	if(B[24]^B[60]) { y[29] = (A[24]&A[60]^A[24]&B[24]^A[60]&B[24]^A[24]&B[60]^A[60]&B[60]^B[24]&B[60]^A[24]^A[25]^A[61]^B[25]^B[60]^B[61]); break; }
    	if(B[24]^B[69]) { y[29] = (A[24]&A[69]^A[24]&B[24]^A[69]&B[24]^A[24]&B[69]^A[69]&B[69]^B[24]&B[69]^A[24]^A[25]^A[70]^B[25]^B[69]^B[70]); break; }
    	if(B[24]^B[78]) { y[29] = (A[24]&A[78]^A[24]&B[24]^A[78]&B[24]^A[24]&B[78]^A[78]&B[78]^B[24]&B[78]^A[24]^A[25]^A[79]^B[25]^B[78]^B[79]); break; }
    } while(0);
    
    do
    {
    	if(A[16]^1) { y[30] = (A[16]&B[16]^A[8]^A[17]^B[8]^B[16]^B[17]); break; }
    	if(B[16]^B[25]) { y[30] = (A[16]&A[25]^A[16]&B[16]^A[25]&B[16]^A[16]&B[25]^A[25]&B[25]^B[16]&B[25]^A[16]^A[17]^A[26]^B[17]^B[25]^B[26]); break; }
    	if(B[16]^B[34]) { y[30] = (A[16]&A[34]^A[16]&B[16]^A[34]&B[16]^A[16]&B[34]^A[34]&B[34]^B[16]&B[34]^A[16]^A[17]^A[35]^B[17]^B[34]^B[35]); break; }
    	if(B[16]^B[43]) { y[30] = (A[16]&A[43]^A[16]&B[16]^A[43]&B[16]^A[16]&B[43]^A[43]&B[43]^B[16]&B[43]^A[16]^A[17]^A[44]^B[17]^B[43]^B[44]); break; }
    	if(B[16]^B[52]) { y[30] = (A[16]&A[52]^A[16]&B[16]^A[52]&B[16]^A[16]&B[52]^A[52]&B[52]^B[16]&B[52]^A[16]^A[17]^A[53]^B[17]^B[52]^B[53]); break; }
    	if(B[16]^B[61]) { y[30] = (A[16]&A[61]^A[16]&B[16]^A[61]&B[16]^A[16]&B[61]^A[61]&B[61]^B[16]&B[61]^A[16]^A[17]^A[62]^B[17]^B[61]^B[62]); break; }
    	if(B[16]^B[70]) { y[30] = (A[16]&A[70]^A[16]&B[16]^A[70]&B[16]^A[16]&B[70]^A[70]&B[70]^B[16]&B[70]^A[16]^A[17]^A[71]^B[17]^B[70]^B[71]); break; }
    } while(0);
    
    do
    {
    	if(A[8]^1) { y[31] = (A[8]&B[8]^A[0]^A[9]^B[0]^B[8]^B[9]); break; }
    	if(B[8]^B[17]) { y[31] = (A[8]&A[17]^A[8]&B[8]^A[17]&B[8]^A[8]&B[17]^A[17]&B[17]^B[8]&B[17]^A[8]^A[9]^A[18]^B[9]^B[17]^B[18]); break; }
    	if(B[8]^B[26]) { y[31] = (A[8]&A[26]^A[8]&B[8]^A[26]&B[8]^A[8]&B[26]^A[26]&B[26]^B[8]&B[26]^A[8]^A[9]^A[27]^B[9]^B[26]^B[27]); break; }
    	if(B[8]^B[35]) { y[31] = (A[8]&A[35]^A[8]&B[8]^A[35]&B[8]^A[8]&B[35]^A[35]&B[35]^B[8]&B[35]^A[8]^A[9]^A[36]^B[9]^B[35]^B[36]); break; }
    	if(B[8]^B[44]) { y[31] = (A[8]&A[44]^A[8]&B[8]^A[44]&B[8]^A[8]&B[44]^A[44]&B[44]^B[8]&B[44]^A[8]^A[9]^A[45]^B[9]^B[44]^B[45]); break; }
    	if(B[8]^B[53]) { y[31] = (A[8]&A[53]^A[8]&B[8]^A[53]&B[8]^A[8]&B[53]^A[53]&B[53]^B[8]&B[53]^A[8]^A[9]^A[54]^B[9]^B[53]^B[54]); break; }
    	if(B[8]^B[62]) { y[31] = (A[8]&A[62]^A[8]&B[8]^A[62]&B[8]^A[8]&B[62]^A[62]&B[62]^B[8]&B[62]^A[8]^A[9]^A[63]^B[9]^B[62]^B[63]); break; }
    } while(0);
    
    // Obtain x from y --- easy-peasy.
    for(i=0; i < 32; ++i)
        x[i] = y[i] ^ A[(256-i*8)%256] ^ B[(256-i*8)%256];
    
    return std::make_pair(x.to_ulong(), y.to_ulong());
}

std::pair<u32,u32> GenerateSerial(const u8 A[32], const u8 B[32])
{
    return Solve(A, B);
}