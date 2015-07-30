/*
Implement strStr() 

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.

*/


int strStr(char* haystack, char* needle) {
    int i=0;
    if (strcmp(haystack, needle) == 0)return 0;
    for(i=0;i<strlen(haystack);i++){
        if(strncmp(haystack+i,needle,strlen(needle))==0)
            return i;
    }
    return -1;
}


int strStr(char* haystack, char* needle) {
	int index = -1;
	int i = 0, j = 0, rec = 0, flag = 0;
	if (strcmp(haystack, needle) == 0)return 0;
	while (i < strlen(haystack)){
		if (haystack[i] == needle[j]){
			if (j == 0){
				flag = 1;
				rec = i;
			}
			i++;
			j++;
		}
		else{
			if (j == strlen(needle))
			{
				index = rec;
				break;
			}
			else
			{
				if (flag == 1)
				{
					i = rec;
					flag = 0;
					j = 0;
				}
				i++;
			}
		}
	}
	if (j == strlen(needle))
	{
		index = rec;
	}
	return index;
}

