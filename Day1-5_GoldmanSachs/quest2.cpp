/*
    Overlapping rectangles
    Question Link: https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/
*/

class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
       int ans = 0;
       int lb1[]={L1[0],R1[1]}, rt1[]={R1[0],L1[1]};
       int lb2[]={L2[0],R2[1]}, rt2[]={R2[0],L2[1]};
       
       
       if(((L1[0]>=L2[0] && L1[0]<=R2[0]) && (L1[1]>=R2[1] && L1[1]<=L2[1])) || ((L2[0]>=L1[0] && L2[0]<=R1[0]) && (L2[1]>=R1[1] && L2[1]<=L1[1])))
       {
           return 1;
       }
       else if((lb1[0]>=L2[0] && lb1[0]<=R2[0]) && (lb1[1]>=R2[1] && lb1[1]<=L2[1]) || ((lb2[0]>=L1[0] && lb2[0]<=R1[0]) && (lb2[1]>=R1[1] && lb2[1]<=L1[1])))
       {
           return 1;
       }
       else if((R1[0]>=L2[0] && R1[0]<=R2[0]) && (R1[1]>=R2[1] && R1[1]<=L2[1]) || ((R2[0]>=L1[0] && R2[0]<=R1[0]) && (R2[1]>=R1[1] && R2[1]<=L1[1])))
       {
           return 1;
       }
       else if((rt1[0]>=L2[0] && rt1[0]<=R2[0]) && (rt1[1]>=R2[1] && rt1[1]<=L2[1]) || ((rt2[0]>=L1[0] && rt2[0]<=R1[0]) && (rt2[1]>=R1[1] && rt2[1]<=L1[1])))
       {
           return 1;
       }
       return ans;
    }
};