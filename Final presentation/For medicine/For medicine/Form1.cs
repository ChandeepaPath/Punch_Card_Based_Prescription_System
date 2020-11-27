using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.OleDb;
using System.IO.Ports;

namespace For_medicine
{
    public partial class Form1 : Form
    {
        void fillform(ComboBox cmb)
        {
            try
            {
                OleDbConnection connection = new OleDbConnection();
                connection.ConnectionString = @"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database2.accdb;
Persist Security Info=False;";
                connection.Open();
                MessageBox.Show("Connection Successful");
                

                // Fill combo box

                string cmd = "select * from Table1";
                OleDbDataAdapter adapter = new OleDbDataAdapter(new OleDbCommand(cmd, connection));
                DataSet ds = new DataSet();
                adapter.Fill(ds);

                cmb.DataSource = ds.Tables[0];
                cmb.DisplayMember = "Medicine";
                cmb.ValueMember = "Code";

                //--------------------------------------


                connection.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error  " + ex);
            }
            cmb.SelectedItem = "--Dose--";
        }
        void filldose(ComboBox cmb)
        {
            try
            {
                OleDbConnection connection = new OleDbConnection();
                connection.ConnectionString = @"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database2.accdb;
Persist Security Info=False;";
                connection.Open();
                //--------------MessageBox.Show("Connection Successful");


                // Fill combo box

                string cmd = "select * from Table2";
                OleDbDataAdapter adapter = new OleDbDataAdapter(new OleDbCommand(cmd, connection));
                DataSet ds = new DataSet();
                adapter.Fill(ds);

                cmb.DataSource = ds.Tables[0];
                cmb.SelectedItem = "dsadsad";
                cmb.DisplayMember = "Dose";
                cmb.ValueMember = "Code";
               // cmb.SelectedText = "--Medicine--";

                //--------------------------------------


                connection.Close();
                
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error  " + ex);
            }
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void Label2_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

            fillform(comboBox1);
            fillform(comboBox2);
            fillform(comboBox3);
            fillform(comboBox4);
            fillform(comboBox5);
            filldose(comboBox6);
            filldose(comboBox7);
            filldose(comboBox8);
            filldose(comboBox9);
            filldose(comboBox10);


            string[] ports = SerialPort.GetPortNames();
            comboBox11.Items.AddRange(ports);
            
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            string a;

            textBox1.Text = comboBox1.SelectedValue.ToString() +  comboBox6.SelectedValue.ToString()+ comboBox2.SelectedValue.ToString() + comboBox7.SelectedValue.ToString() + comboBox3.SelectedValue.ToString() + comboBox8.SelectedValue.ToString() + comboBox4.SelectedValue.ToString() + comboBox9.SelectedValue.ToString() + comboBox5.SelectedValue.ToString()+ comboBox10.SelectedValue.ToString();
            string aa = textBox1.Text;
            char[] ch;
            ch = aa.ToCharArray();

            SerialPort port = new SerialPort(comboBox11.Text,2400, Parity.None, 8, StopBits.One);
            port.Open();
           
            //port.Write(textBox1.Text+"\n");
            for(int i=0;i<20;i++)
            {
                string aaa = ch[i].ToString();
                port.Write(aaa);
                System.Threading.Thread.Sleep(100);
            }   
            
            
            port.Close();
        }

        private void ComboBox6_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
