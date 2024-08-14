<!DOCTYPE html>
<html>
<head>  

  <img src="https://www.phoneworld.com.pk/wp-content/uploads/2022/04/Tips-to-keep-your-Instagram-account-safe.jpg" alt="Instagram Logo" style="width:300px;height:120px;">
  <h1 style="font-size:20px">&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspCreate a new account</h1>

</head>

<body>

        <form runat="server"> 

        <label for="fname">First Name:</label>
        <asp:TextBox ID="fname" runat="server"></asp:TextBox> &nbsp
        <label for="lname">Last Name:</label>
        <asp:TextBox ID="lname" runat="server"></asp:TextBox> <br /><br />

        <label for="username">Username:</label>
        <asp:TextBox ID="username" runat="server"></asp:TextBox> <br /><br />

        <label for="pass">Password:</label>
        <asp:TextBox ID="txtPassword" runat="server"></asp:TextBox><br /><br />

         <label for="dob">Date of Birth:</label>
         <input type="date" id="dob" name="dob"> <br><br>

          <label for="country">Country:</label>
          <asp:DropDownList ID="country" runat="server">
          <asp:ListItem Text="Select" Value="0"></asp:ListItem>
          <asp:ListItem Text="Pakistan" Value="Pak"></asp:ListItem>
          <asp:ListItem Text="United States" Value="US"></asp:ListItem>
          <asp:ListItem Text="England" Value="UK"></asp:ListItem>
          </asp:DropDownList><br><br>

          <label for="gender">Gender:</label>
          <asp:RadioButton Text ="Male" GroupName="Gender" runat="server" />
          <asp:RadioButton Text ="Female" GroupName="Gender" runat="server" /><br><br>

          <asp:CheckBox ID="priv" runat="server" />
          <label for="priv"> Enable Privacy</label><br><br>

           <asp:Button ID="signin" Text="Sign In" runat="server" />

         </form>
 
<%--//normal html below--%>
         <%--<label for="username">First Name:</label>
         <input type="text" id="name" name="name"> &nbsp

         <label for="lname">Last Name:</label>
         <input type="text" id="lname" name="lname"> <br><br>
         
         <label for="username">Username:</label>
         <input type="text" id="uname" name="name"> <br><br>

         <label for="pass">Password:</label>
         <input type="text" id="pass" name="pass"> <br><br>

   
         <label for="dob">Date of Birth:</label>
         <input type="date" id="dob" name="dob"> <br><br>

         <label for="country">Country:</label>
            <select name="country" id="country">
                <option value="pak">Pakistan</option>
                <option value="us">United States</option>
                <option value="uae">UAE</option>
                <option value="uk">England</option>
            </select> <br><br>

          <label for="gender">Gender:</label>
          <input type="radio" id="radio1" name="gender" value="male">
          <label for="radio1">Male</label>
          <input type="radio" id="radio2" name="gender" value="female">
          <label for="radio2">Female</label> <br><br>

      <input type="checkbox" id="priv" name="priv" value="priv">
      <label for="priv"> Enable Privacy</label><br><br>

      <input type="submit" value="Sign In">--%>

</body>
</html>