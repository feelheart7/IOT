package com.iot.servlet;
import java.io.DataOutputStream;
import java.io.IOException;
//import java.sql.ResultSet;
//import java.sql.SQLException;
import java.util.HashMap;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import com.google.gson.Gson;
import com.iot.database.DBManager;

public class Insert extends HttpServlet {
    private final static long serialVersionUID = 1L;
    public Insert() {
        super();
    }
    public void destroy() {
        super.destroy(); // Just puts "destroy" string in log
        // Put your code here
    }

    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
       
    	request.setCharacterEncoding("UTF-8");
        response.setContentType("text/html; charset=UTF-8" );
        DataOutputStream dos = new DataOutputStream(response.getOutputStream());
        String heartbeat = request.getParameter("h");//h代表心跳
        String result = doInsertHeartBeat(heartbeat);        
        System.out.println("result = " + result);
        dos.writeUTF(result);
    }
    
    private  String doInsertHeartBeat(String heartbeat)
    {
     HashMap<String, Object> result = new HashMap<String, Object>();
     String sql = "INSERT INTO `heartbeat` (`id`, `heartbeat`, `datetime`) VALUES ('1', "+"'" + heartbeat + "', CURRENT_TIMESTAMP);" ;
     System.out.println("url = " + sql);
     DBManager db = new DBManager(); 
     int executeResult = db.update(sql);
     
     if(executeResult == 0) {
         result.put("result_code", 2);
     } else {
         result.put("result_code", 0);
     }
 
 return (new Gson()).toJson(result);
}
    
  
    
    
    public void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        doGet(request,response);

    }
    public void init() throws ServletException {
        // Put your code here
    }

}


