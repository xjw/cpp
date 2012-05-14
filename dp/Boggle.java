import java.util.*;

public class Boggle {

    // problem 1: print all boggle words
    Set<String> set = new HashSet<String>(Arrays.asList("test", "ted"));

    void printBoggleWords(char[][] x, int i, int j, String s, boolean[][] visited) {
        if (i<0 || j< 0 || i>=x.length || j>=x[0].length || visited[i][j]) return;

        if (set.contains(s)) System.out.println(s);

        visited[i][j] = true;

        String new_s = s + x[i][j];
        printBoggleWords(x, i-1, j, new_s, visited);
        printBoggleWords(x, i+1, j, new_s, visited);
        printBoggleWords(x, i, j+1, new_s, visited);
        printBoggleWords(x, i, j-1, new_s, visited);

        visited[i][j] = false;
    }

    void testPrintBoggleWords() {
        char[][] x = {
            {'t', 's'},
            {'e', 'd'}
        };
        boolean[][] y = new boolean[x.length][x[0].length];
        for (int i=0; i<x.length; i++) {
            for (int j=0; j<x[i].length; j++) {
                printBoggleWords(x, i, j, "", y);
            }
        }
    }


    // problem 2: determine whether string exists in matrix 
    void testStringInMatrix() {
        char[][] x = new char[][] {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
        };
        boolean[][] visited = new boolean[x.length][x[0].length];
        String word = "ABCB";
        //String word = "ABCCED";
        for (int i=0; i<x.length; i++) {
            for (int j=0; j<x[i].length; j++) {
                if (stringInMatrix(x, word, "", i, j, visited)) {
                    System.out.println("yep");
                    return;
                }
            }
        }
    }

    boolean stringInMatrix(char[][] x, String word, String s, int i, int j, boolean[][] visited) {
        if (i<0 || j<0 || i>=x.length || j >=x[0].length || visited[i][j]) return false;
        if (s.equals(word)) return true;
        visited[i][j] = true;
        String new_s = s + x[i][j];
        if (stringInMatrix(x, word, new_s, i+1, j, visited)
                || stringInMatrix(x, word, new_s, i-1, j, visited)
                || stringInMatrix(x, word, new_s, i, j+1, visited)
                || stringInMatrix(x, word, new_s, i, j-1, visited)) 
            return true;
        visited[i][j] = false;
        return false;
    }

    public static void main(String[] args) {
        Boggle b = new Boggle();
        b.testStringInMatrix();
    }


}
