using System;
using System.Linq;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace EleVrPDA
{
  public partial class Form1 : Form
  {
    int conta;

    public Form1()
    {
      InitializeComponent();
      conta = 0;
    }

    private void button1_Click(object sender, EventArgs e)
    {
      if (conta == 0)
      {
        button1.BackColor = Color.Green;
        conta++;
      }
      else if (conta == 1)
      {
        button1.BackColor = Color.Blue;
        conta++;
      }
      else if (conta == 2)
      {
        button1.BackColor = Color.Black;
        conta++;
      }
      else if (conta == 3)
      {
        button1.BackColor = Color.LimeGreen;
        conta = 0;
      }
    }

    private void Form1_Load(object sender, EventArgs e)
    {
 
    }

    private void Form1_Click(object sender, EventArgs e)
    {
      Close();
    }
  }
}