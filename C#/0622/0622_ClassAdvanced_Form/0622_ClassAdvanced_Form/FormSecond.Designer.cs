namespace _0622_ClassAdvanced_Form
{
    partial class FormSecond
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
            this.labelReceive = new System.Windows.Forms.Label();
            this.labelShowCount = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // labelReceive
            // 
            this.labelReceive.AutoSize = true;
            this.labelReceive.Location = new System.Drawing.Point(12, 9);
            this.labelReceive.Name = "labelReceive";
            this.labelReceive.Size = new System.Drawing.Size(81, 12);
            this.labelReceive.TabIndex = 0;
            this.labelReceive.Text = "Form Second";
            // 
            // labelShowCount
            // 
            this.labelShowCount.AutoSize = true;
            this.labelShowCount.Location = new System.Drawing.Point(12, 66);
            this.labelShowCount.Name = "labelShowCount";
            this.labelShowCount.Size = new System.Drawing.Size(50, 12);
            this.labelShowCount.TabIndex = 1;
            this.labelShowCount.Text = "Count : ";
            // 
            // FormSecond
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(352, 273);
            this.Controls.Add(this.labelShowCount);
            this.Controls.Add(this.labelReceive);
            this.Name = "FormSecond";
            this.Text = "FormSecond";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelReceive;
        private System.Windows.Forms.Label labelShowCount;
    }
}