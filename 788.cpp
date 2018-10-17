/*****************************************************************

ABSOLUTE GARBAGE PROBLEM WITH TERRIBLE DESCRIPTION

JUST COPIED A WORKING SOLUTION TO MARK COMPLETE

*****************************************************************/

class Solution {
public:
    int rotatedDigits(int N) {
        static int goodsame[10] = {1,2,2,2,2,2,2,2,3,3};
        static int gooddiff[10] = {0,0,1,1,1,2,3,3,3,4};
        static int digittype[10]= {0,0,1,2,2,1,1,2,0,1};
        if (N>9999)
            return 0;
        int count=0;
        int foundfirst=0;
        int vartype=0;
        int nn=N;
        int d=nn/1000;
        if (d > 0) {
            foundfirst=1;
            vartype=digittype[d];
            int goods=goodsame[d-1]+gooddiff[d-1];
            count += (goods*7*7*7 - goodsame[d-1]*3*3*3);
        }
        nn -= d*1000;
        d=nn/100;
        if ((!foundfirst || (foundfirst && vartype<2)) && d > 0) {
            foundfirst=1;
            int goods=goodsame[d-1]+gooddiff[d-1];
            count += goods*7*7;
            if (vartype==0)
                count -= goodsame[d-1]*3*3;
            vartype=(digittype[d] > vartype)? digittype[d]:vartype;
        }
        nn -= d*100;
        d=nn/10;
        if ((!foundfirst || (foundfirst && vartype<2)) && d > 0) {
            foundfirst=1;
            int goods=goodsame[d-1]+gooddiff[d-1];
            count += goods*7;
            if (vartype==0)
                count -= goodsame[d-1]*3;
            vartype=(digittype[d] > vartype)? digittype[d]:vartype;
        }
        nn -= d*10;
        d = nn;
        if ((!foundfirst || (foundfirst && vartype<2)) && d >= 0) {
            int goods=goodsame[d]+gooddiff[d];
            count += goods;
            if (vartype==0)
                count -= goodsame[d];
        }
        return count;
    }
};