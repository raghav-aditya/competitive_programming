under 8 minute CR:

package com.example.practice;

import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.PostConstruct;
import java.util.*;

@Service
public class MemberAccessService {

    private JdbcTemplate jdbc;

    private Map<String, Integer> loginAttempts = new HashMap<>();
    private static String lastAccessedUser = null;
    private boolean featureFlag = false;

    @PostConstruct
    public void init() {
        List<Map<String, Object>> rows =
                jdbc.queryForList("SELECT username, attempts FROM login_attempts");

        for (Map<String, Object> row : rows) {
            loginAttempts.put(
                    (String) row.get("username"),
                    (Integer) row.get("attempts")
            );
        }
    }

    public boolean authenticate(String username, String password) {

        if (featureFlag) {
            return true;
        }

        String sql = "SELECT COUNT(*) FROM members WHERE username = '" + username +
                "' AND password = '" + password + "'";

        Integer count = jdbc.queryForObject(sql, Integer.class);

        if (count == 1) {
            loginAttempts.put(username, 0);
            return true;
        }

        loginAttempts.put(username, loginAttempts.getOrDefault(username, 0) + 1);

        return false;
    }

    public String getLastAccessedUser() {
        return lastAccessedUser;
    }

    public void setFeature(boolean f) {
        this.featureFlag = f;
    }
}









/*
    CR: 
         1: jdbc DI is missing, User constructor injection 
         2: Cache refresh is missing 
         3: Our Cache is not Thread Safe, use ConcurrenthashMap, 
         4: Feature Flage logic is bit skewd, Correct the UseCase, featureFlag should be used for feature but authentication is default for all login attempts 
         5: SQL Injection might be possible in current setup, validate both username and password for special charactors
         6: use prepared statements for SQL query instead of of generating from String.
         7: make the feature flage volatile as multiple threads will be using the instance of class they all should be aware of it
         8: make a new functions for cacherefersh so that cache will be freshs
         9: user proper variable name for setFeature() function



*/