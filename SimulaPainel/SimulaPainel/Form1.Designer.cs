namespace SimulaPainel
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
			this.Ele1 = new System.Windows.Forms.Button();
			this.Ele2 = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// Ele1
			// 
			this.Ele1.BackColor = System.Drawing.Color.Red;
			this.Ele1.Location = new System.Drawing.Point(64, 65);
			this.Ele1.Name = "Ele1";
			this.Ele1.Size = new System.Drawing.Size(40, 10);
			this.Ele1.TabIndex = 0;
			// 
			// Ele2
			// 
			this.Ele2.BackColor = System.Drawing.Color.Red;
			this.Ele2.Location = new System.Drawing.Point(128, 65);
			this.Ele2.Name = "Ele2";
			this.Ele2.Size = new System.Drawing.Size(40, 10);
			this.Ele2.TabIndex = 1;
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(96F, 96F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Dpi;
			this.AutoScroll = true;
			this.BackColor = System.Drawing.Color.Black;
			this.ClientSize = new System.Drawing.Size(240, 320);
			this.ControlBox = false;
			this.Controls.Add(this.Ele2);
			this.Controls.Add(this.Ele1);
			this.Location = new System.Drawing.Point(0, 0);
			this.MinimizeBox = false;
			this.Name = "Form1";
			this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Button Ele1;
		private System.Windows.Forms.Button Ele2;
	}
}

