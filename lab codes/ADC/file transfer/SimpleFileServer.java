import java.io.BufferedInputStream; 
import java.io.File;
 import java.io.FileInputStream; 
import java.io.IOException; 
import java.io.OutputStream; 
import java.net.ServerSocket; 
import java.net.Socket;
 public class SimpleFileServer {
 public final static int SOCKET_PORT = 13267; // you may change this public final
 
public static void main (String [] args ) throws IOException {
//FILE_TO_SEND = "/home/vssut/Desktop/FileTransfer/new.txt";
 FileInputStream fis = null; 
BufferedInputStream bis = null; 
OutputStream os = null; ServerSocket servsock = null;
 Socket sock = null; 
try { servsock = new ServerSocket(SOCKET_PORT);
 while (true) { System.out.println("Waiting..."); 
try { 
sock = servsock.accept(); 
System.out.println("Accepted connection : " + sock); // send file 
File myFile = new File ("/media/rockngsho/SHOVAN/lab/ADC/file transfer/new.txt");
 byte [] mybytearray = new byte [(int)myFile.length()]; 
fis = new FileInputStream(myFile); bis = new BufferedInputStream(fis);
 bis.read(mybytearray,0,mybytearray.length); os = sock.getOutputStream(); 
System.out.println("Sending "  + "(" + mybytearray.length + " bytes)"); 
os.write(mybytearray,0,mybytearray.length); 
os.flush(); System.out.println("Done."); } 
finally { if (bis != null) bis.close(); if (os != null) os.close(); if (sock!=null) sock.close(); } 
	} 
} 
finally { if (servsock != null) servsock.close(); 
		} 
	} 
} 
