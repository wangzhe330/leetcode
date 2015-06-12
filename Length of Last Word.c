/*

Length of Last Word 

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5. 

*/

int lengthOfLastWord(char* s) {
    int count =0;
    char* index = s;
    char* end = s;
    while(*end != 0)end++;
    if(end == index)return 0;
    index = end-1;
    while(*index == ' ' && index >= s){
        index--;
    }
    while(*index!=' ' && index >= s){
        count ++;
        index --;
    }
    return count;
}