package com.iot.database;
//import java.awt.List;
import java.sql.*;
//import java.util.ArrayList;
//import java.util.HashMap;
//import java.lang.Object;
import com.mysql.jdbc.Connection;

public class DBManager {

    public final static String TABLE_NAME = "heartbeat";



    public Statement getStatement() {
        Connection connection = null;
        Statement stmt = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");

            connection = (Connection) DriverManager.getConnection("jdbc:mysql://localhost:3306/IOT?useUnicode=true&characterEncoding=UTF-8", "root", "root");
            stmt = connection.createStatement();
        } catch (ClassNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        return stmt;
    }

    

    public ResultSet query(String sql) {
        ResultSet rst = null;
        Statement stmt = getStatement();
        System.out.println("stmt = " + stmt);
        try {
            rst = stmt.executeQuery(sql);
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        return rst;
    }

    public int update(String sql) {
        Statement stmt = getStatement();
        int result = 0;
        try {
            result = stmt.executeUpdate(sql);
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        return result;
    }
}
