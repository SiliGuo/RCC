//Filename JInsurance.java
//Written by <Sili Guo>
//Written on <02/09/2017>
package jInsurance;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.ButtonGroup;

public class JInsurance extends JFrame implements ItemListener {
	final int HMO_PRICE = 200;
	final int PPO_PRICE = 600;
	final int DEN_PRICE = 75;
	final int VIS_PRICE = 20;
	int total = 0;

	JCheckBox hmo = new JCheckBox("HMO (Health Maintenance Organization)", false);
	JCheckBox ppo = new JCheckBox("PPO (Preferred Provider Organization)", false);
	JCheckBox dental = new JCheckBox("Dental Coverage", false);
	JCheckBox vision = new JCheckBox("Vision Care", false);
	ButtonGroup aGroup = new ButtonGroup();
	

	JLabel label = new JLabel("Please Check the Plan:");
	JLabel price = new JLabel("The plan you chose and the total charge:");
	JTextField field1 = new JTextField(18);
	JTextField field2 = new JTextField(18);
	JTextField field3 = new JTextField(18);
	JTextField field4 = new JTextField(18);

	public JInsurance() {
		super("Health Insurance Plan");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new FlowLayout());
		aGroup.add(hmo);
		aGroup.add(ppo);
		add(label);
		add(hmo);
		add(ppo);
		add(dental);
		add(vision);
		add(price);
		add(field1);
		add(field2);
		add(field3);
		add(field4);
		hmo.addItemListener(this);
		ppo.addItemListener(this);
		dental.addItemListener(this);
		vision.addItemListener(this);
		field4.setText("The Total: $" + total);
	}

	public void itemStateChanged(ItemEvent event) {
		Object source = event.getSource();
		int select = event.getStateChange();
		if (source == hmo) {
			if (select == ItemEvent.SELECTED) {
				field1.setText("HMO  $" + HMO_PRICE);
				total += HMO_PRICE;
			} else {
				field1.setText(" ");
				total -= HMO_PRICE;
			}
		} else if (source == ppo) {
			if (select == ItemEvent.SELECTED) {
				field1.setText("PPO  $" + PPO_PRICE);
				total += PPO_PRICE;
			} else {
				field1.setText(" ");
				total -= PPO_PRICE;
			}
		} else if (source == dental) {
			if (select == ItemEvent.SELECTED) {
				field2.setText("Dental Coverage  $" + DEN_PRICE);
				total += DEN_PRICE;
			} else {
				field2.setText(" ");
				total -= DEN_PRICE;
			}
		} else if (source == vision) {
			if (select == ItemEvent.SELECTED) {
				field3.setText("Vision Cure  $" + VIS_PRICE);
				total += VIS_PRICE;
			} else {
				field3.setText(" ");
				total -= VIS_PRICE;
			}
		}
		field4.setText("The Total: $" + total);
	}

	public static void main(String[] args) {
		JInsurance aFrame = new JInsurance();
		final int WIDTH = 400;
		final int HEIGHT = 300;
		aFrame.setSize(WIDTH, HEIGHT);
		aFrame.setVisible(true);
	}
}
