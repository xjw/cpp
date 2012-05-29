import java.util.*;
import java.io.*;

public class ReadFile {
    void countWordsAndLines(String file) {
        int word_count = 0;
        int line_count = 0;
        try {
            Scanner sc = new Scanner(new File(file));
            while (sc.hasNextLine()) {
                Scanner sc2 = new Scanner(sc.nextLine());
                while (sc2.hasNext()) {
                    word_count++;
                    sc2.next();
                }
                line_count++;
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println(word_count);
        System.out.println(line_count);
    }

    public static void main(String[] args) {
        new ReadFile().countWordsAndLines("test.txt");
    }
}
