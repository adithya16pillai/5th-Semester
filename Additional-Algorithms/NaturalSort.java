import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
public class NaturalSort {
    public static void main(String[] args) {
        List<String> strings = new ArrayList<>();
        strings.add("file1.txt");
        strings.add("file10.txt");
        strings.add("file2.txt");
        strings.add("file20.txt");
        strings.add("file3.txt");
        List<String> sortedStrings = naturalSort(strings);
        for (String str : sortedStrings) {
            System.out.println(str);
        }
    }
    public static List<String> naturalSort(List<String> strings) {
        strings.sort(Comparator.comparing(NaturalSort::extractNumericParts).thenComparing(Comparator.naturalOrder()));
    return strings;
    }
    private static List<String> extractNumericParts(String str) {
        List<String> numericParts = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\d+");
        Matcher matcher = pattern.matcher(str);
        while (matcher.find()) {
            numericParts.add(matcher.group());
        }
        return numericParts;
    }
}