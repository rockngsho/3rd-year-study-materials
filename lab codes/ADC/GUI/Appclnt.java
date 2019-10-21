import java.net.*;
import java.io.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
class Appclnt extends Frame implements ActionListener,Runnable{
TextField t1;
Button b1;
TextArea ta;
PrintStream p;
BufferedReader br;
Panel p1=new Panel(),p2=new Panel();
public Appclnt(){
 super("client");
setFont(new Font("Comic Sans MS",Font.PLAIN,20));
setLayout(new BorderLayout());
p1.setBackground(new Color(0.28F,0.40F,0.32F));
p2.setBackground(new Color(0.28F,0.40F,0.32F));
p2.setLayout(new FlowLayout());
t1=new TextField(10);
b1=new Button("Send");
p2.add(t1);
p2.add(b1);
b1.addActionListener(this);
WindowAdapter w1=new WindowAdapter(){
  public void windowClosing(WindowEvent we){
   System.exit(0);
}};
addWindowListener(w1);
add("North",p1);
add("Center",ta=new TextArea(6,6));
add("South",p2);
setSize(500,500);
setVisible(true);
try{
    Socket s=new Socket(InetAddress.getLocalHost(),12345);
     p=new PrintStream(s.getOutputStream(),true);
     br=new BufferedReader(new InputStreamReader(s.getInputStream()));
    Thread t1=new Thread(this);
     t1.start();
}catch(Exception e){}
};
public void actionPerformed(ActionEvent ae){
String z; 
 try{z=t1.getText();  
 p.println(z);
  ta.append("you:"+z+"\n");
 t1.setText("");}catch(Exception e){}
}
public void run(){
 while(true){
  try{
     ta.append("server:"+br.readLine()+"\n");
  }catch(Exception e){}
}
}
 public static void main(String args[]) throws Exception{    
  new Appclnt();
}};
