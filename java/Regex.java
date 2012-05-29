public class Regex {
    static boolean validatePhoneNumber(String s) {
        return s.matches("^\\(?\\d{3}\\)?[-.\\s]?\\d{3}\\d{4}$");
    }

    public static void main(String[] args) {
        System.out.println(validatePhoneNumber("(408)-6212066"));
    }
}
