package JAVA.GUU.RU.LAB5;

//Класс для отчистки
public class CodeCleaner
{
    //Удаление комментариев и литералов
    public static String killCommentsNStrings(String code)
    {
        code = removeStringLiterals(code); //Строковые литералы в расход
        code = removeCharLiterals(code); //Символьные литералы в расход
        code = removeMultiComments(code); //Многострочныйе комментарии в расход
        code = removeSingleComments(code); //Однострочные комментарии в расход

        return code;
    }

    private static String removeStringLiterals(String code)
    {
        StringBuilder result = new StringBuilder();
        boolean inString = false;

        for (int i = 0; i < code.length(); i++)
        {
            char c = code.charAt(i);

            if (c == '"' && (i == 0 || code.charAt(i - 1) != '\\'))
            {
                inString = !inString;
                result.append('"');
            }
            else
                result.append(c);
        }
        return result.toString();
    }

    private static String removeCharLiterals(String code)
    {
        StringBuilder result = new StringBuilder();
        boolean inChar = false;

        for (int i = 0; i < code.length(); i++)
        {
            char c = code.charAt(i);

            if (c == '\'' && (i == 0 || code.charAt(i - 1) != '\\'))
            {
                inChar = !inChar;
                result.append('\'');
            }
            else if (!inChar)
                result.append(c);
        }
        return result.toString();
    }

    private static String removeMultiComments(String code)
    {
        StringBuilder result = new StringBuilder();
        boolean inComment = false;

        for (int i = 0; i < code.length(); i++)
        {
            if (!inComment && i < code.length() - 1 && code.charAt(i) == '*' && code.charAt(i + 1) == '/')
            {
                inComment = false;
                i++;
            }
            else if (!inComment)
                result.append(code.charAt(i));
        }
        return result.toString();
    }

    private static String removeSingleComments(String code)
    {
        StringBuilder result = new StringBuilder();
        boolean inComment = false;

        for (int i = 0; i < code.length(); i++)
        {
            if (!inComment && i < code.length() - 1 && code.charAt(i) == '/' && code.charAt(i + 1) == '/')
            {
                inComment = true;
                i++;
            }
            else if (inComment && code.charAt(i) == '\n')
            {
                inComment = false;
                result.append('\n');
            }
            else if (!inComment)
                result.append(code.charAt(i));
        }
        return result.toString();
    }
}
