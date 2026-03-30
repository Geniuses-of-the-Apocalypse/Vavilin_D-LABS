package main.guu.ru.lab7.service;

import org.springframework.stereotype.Service;
import java.util.*;

@Service("basePathFinder")
public class BasePathFinder implements PathFinder {

    @Override
    public List<String> findPath(String start, String end) {
        return new ArrayList<>();
    }
}
