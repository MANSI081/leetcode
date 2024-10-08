class Solution {
public:

// /BALNCED IF AND ONLY IF 
// BEFORE BALANCED==> ]][]][[[][  ===> JO BALNCED HAI UNKO IGNORE KAR DO
// AFTER BALANCED===> ]]][[[ ==>ISI FORMAT ME HOGA HAMESH 
// AND IN QUESTION GIVEN EQUAL NUMBER OF OPENING AND EQUAL NUMBER OF CLOSING
// THOUGHT 1
// (NUMBER OF OPENING BRACKET+1)/2

// STACK IS THE BEST APPROACH FOR PARENTHESIS REATED PROBLEM
// AGAR OPEN BRACKET HAI TABHI STACK ME DALNA HAI
// NHI TO CLOSE BRACKET HAI CHECK KAR LO STACK KE TOP PE KOI OPEN BRACKET HAI , AGR HAI TOH POP KAR DO


// 
    int minSwaps(string s) {

    // with stack
        stack<char>st;

        for(char &ch: s){
            if(ch=='['){
                st.push(ch);
            } else if(!st.empty()){
                st.pop(); //balancing closing bracket with an open bracket in stack

            }
        }
        // size of stack= number of open barckets in the stack
        return (st.size()+1)/2;
    }
};
