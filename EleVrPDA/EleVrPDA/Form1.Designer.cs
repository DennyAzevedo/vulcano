namespace EleVrPDA
{
  partial class Form1
  {
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
    protected override void Dispose(bool disposing)
    {
      if (disposing && (components != null))
      {
        components.Dispose();
      }
      base.Dispose(disposing);
    }

    #region Windows Form Designer generated code

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
      this.button1 = new System.Windows.Forms.Button();
      this.SuspendLayout();
      // 
      // button1
      // 
      this.button1.BackColor = System.Drawing.Color.LimeGreen;
      this.button1.Location = new System.Drawing.Point(109, 127);
      this.button1.Name = "button1";
      this.button1.Size = new System.Drawing.Size(20, 20);
      this.button1.TabIndex = 0;
      this.button1.Click += new System.EventHandler(this.button1_Click);
      // 
      // Form1
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(96F, 96F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Dpi;
      this.AutoScroll = true;
      this.BackColor = System.Drawing.Color.White;
      this.ClientSize = new System.Drawing.Size(240, 320);
      this.ControlBox = false;
      this.Controls.Add(this.button1);
      this.Location = new System.Drawing.Point(0, 0);
      this.MinimizeBox = false;
      this.Name = "Form1";
      this.Text = "Form1";
      this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
      this.Load += new System.EventHandler(this.Form1_Load);
      this.Click += new System.EventHandler(this.Form1_Click);
      this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.Button button1;
  }
}

