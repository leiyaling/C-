<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'index.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>
    <h3>
    	<a href="index">查询图书类别</a>
    	<a href="addCatalogView">添加图书类别</a>
    </h3>
    
    <table>
    	<tr>
    		<td>ID</td>
    		<td>图书类名</td>
    		<td>操作</td>
    	</tr>
    	<c:forEach items="${requestScope.catalogList}" var="catalogList">
    		<tr>
    			<td>${catalogList.catalogid }</td>
    			<td>${catalogList.catalogname }</td>
    			<td>
    				<a href="updateCatalogView?catalogid=${catalogList.catalogid }">修改</a>
    				<a href="deleteCatalog?catalogid=${catalogList.catalogid }" onclick="javascript:return confirm('确认删除图书吗?')">删除</a>
    			</td>
    		</tr>
    	</c:forEach>
    </table>
  </body>
</html>
