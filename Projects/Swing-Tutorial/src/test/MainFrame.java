package test;


import javax.swing.*;



public class MainFrame {

	    public static void main(String[] args) {
	        SwingUtilities.invokeLater(new Runnable() {
	            public void run() {
	                JFrame frame = new JFrame("SWING Tutorial");
	                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	                
	                
	                JButton button = new JButton("Click me :)");
	                frame.add(button);
	                
	                frame.setSize(300, 200);
	                frame.setVisible(true);
	                
	                
	            }
	            
	            
	            
	        });
	    }
	    
	    
	    
	    
	    
	}
