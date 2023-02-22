 int strStr(string haystack, string needle) {
        int i = 0;//主串开始的下标
        int j = 0;//子串开始的下标
        while (i < haystack.size() && j < needle.size())
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                i = i - j + 1;
                j = 0;
                
            }
        }
        //如果子串走到空，代表找到了
        if (j >= needle.size())
        {
            return i - j;
        }
        else{
            //如果主串走到空，证明主串里没有子串
            return -1;
        }
        

    }
