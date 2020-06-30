namespace _0622_ClassAdvanced_Form
{
    partial class FormDialog
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
            this.Dialoglabel01 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // Dialoglabel01
            // 
            this.Dialoglabel01.AutoSize = true;
            this.Dialoglabel01.Location = new System.Drawing.Point(12, 9);
            this.Dialoglabel01.Name = "Dialoglabel01";
            this.Dialoglabel01.Size = new System.Drawing.Size(69, 12);
            this.Dialoglabel01.TabIndex = 0;
            this.Dialoglabel01.Text = "FormDialog";
            // 
            // FormDialog
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(388, 301);
            this.Controls.Add(this.Dialoglabel01);
            this.Name = "FormDialog";
            this.Text = "FormDialog";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Dialoglabel01;
    }
}