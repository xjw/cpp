/*
 * http://olehuisha.wordpress.com/2011/04/14/file-operations-io-readerwriter/
 * http://www.mitbbs.com/article_t1/JobHunting/32101029_0_1.html
 
 给你一个 char* read4096() 的API，一次返回小于或者等于4096个字符。
 如果返回是小于4096个字符，意味着已经读到文件末尾 '\0'。

 用read4096()这个API，写一个 char* readline() 的function。
 要求：
    #1 readline（）returns when reading '\n' or '\0';
    #2 readline() may be called multiple times on a file, the return value 
       should be correct.
    #3 readline() may return char array longer than 4096 chars.
 */
public class ReadLine {
    static char[] buf = null;
    int p = 0;

    char[] readline() {
        StringBuilder sb = new StringBuilder();
        if (buf == null) {
            buf = read4096();
        }
        while(true) {
            if (buf == null || buf.length == 0) break;

            while (p < buf.length) {
                if (buf[p] == '\0' || buf[p] == '\n') {
                    p++;
                    return sb.toString().toCharArray();
                }
                sb.append(buf[p]);
                p++;
            }

            if (buf.length < 4096) break;
            // continue reading if not file end yet
            p = 0;
            buf = read4096();
        }
        return sb.toString().toCharArray();
    }


    char[] read4096() {
        return new char[4096];
    }
}
