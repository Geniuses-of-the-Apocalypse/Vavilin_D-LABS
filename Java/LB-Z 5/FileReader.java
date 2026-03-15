package JAVA.GUU.RU.LAB5;

import java.io.*;
import java.nio.file.*;

public class FileReader
{
    public static String readFile(String filePath) throws IOException
    {
        return new String(Files.readAllBytes(Paths.get(filePath)));
    }

    public static boolean fileExists(String filePath)
    {
        return Files.exists(Paths.get(filePath));
    }

    public static String getFileExtension(String filePath)
    {
        int lastDot = filePath.lastIndexOf('.');
        if (lastDot > 0)
            return filePath.substring(lastDot + 1);
        return "";
    }
}
