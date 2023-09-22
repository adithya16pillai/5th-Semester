import java.util.*;

public class HyphenToBeginning {
    public static void main(String args[]) {
        String originalString = "test";
        String transformedString = moveHyphenToBeginning(originalString);
        System.out.println(transformedString);
    }
    public static String moveHyphenToBeginning(String string) {
        if (string.contains("-")) {
            int hyphenIndex = string.indexOf("-");
            return "-" + string.substring(0, hyphenIndex) + string.substring(hyphenIndex + 1);
        } else {
            return string;
        }

    }
}
