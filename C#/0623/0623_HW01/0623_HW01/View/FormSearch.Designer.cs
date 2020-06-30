namespace _0623_HW01.View
{
    partial class FormSearch
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.textBoxContent = new System.Windows.Forms.TextBox();
            this.buttonSearch = new System.Windows.Forms.Button();
            this.radioButtonName = new System.Windows.Forms.RadioButton();
            this.radioButtonPhone = new System.Windows.Forms.RadioButton();
            this.radioButtonAge = new System.Windows.Forms.RadioButton();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.radioButtonAge);
            this.groupBox1.Controls.Add(this.radioButtonPhone);
            this.groupBox1.Controls.Add(this.radioButtonName);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(281, 100);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Select";
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(12, 145);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 23;
            this.dataGridView1.Size = new System.Drawing.Size(281, 352);
            this.dataGridView1.TabIndex = 1;
            // 
            // textBoxContent
            // 
            this.textBoxContent.Location = new System.Drawing.Point(12, 118);
            this.textBoxContent.Name = "textBoxContent";
            this.textBoxContent.Size = new System.Drawing.Size(200, 21);
            this.textBoxContent.TabIndex = 2;
            // 
            // buttonSearch
            // 
            this.buttonSearch.Location = new System.Drawing.Point(218, 116);
            this.buttonSearch.Name = "buttonSearch";
            this.buttonSearch.Size = new System.Drawing.Size(75, 23);
            this.buttonSearch.TabIndex = 3;
            this.buttonSearch.Text = "SEARCH";
            this.buttonSearch.UseVisualStyleBackColor = true;
            this.buttonSearch.Click += new System.EventHandler(this.buttonSearch_Click);
            // 
            // radioButtonName
            // 
            this.radioButtonName.AutoSize = true;
            this.radioButtonName.Location = new System.Drawing.Point(6, 20);
            this.radioButtonName.Name = "radioButtonName";
            this.radioButtonName.Size = new System.Drawing.Size(59, 16);
            this.radioButtonName.TabIndex = 4;
            this.radioButtonName.TabStop = true;
            this.radioButtonName.Text = "NAME";
            this.radioButtonName.UseVisualStyleBackColor = true;
            // 
            // radioButtonPhone
            // 
            this.radioButtonPhone.AutoSize = true;
            this.radioButtonPhone.Location = new System.Drawing.Point(6, 42);
            this.radioButtonPhone.Name = "radioButtonPhone";
            this.radioButtonPhone.Size = new System.Drawing.Size(65, 16);
            this.radioButtonPhone.TabIndex = 5;
            this.radioButtonPhone.TabStop = true;
            this.radioButtonPhone.Text = "PHONE";
            this.radioButtonPhone.UseVisualStyleBackColor = true;
            // 
            // radioButtonAge
            // 
            this.radioButtonAge.AutoSize = true;
            this.radioButtonAge.Location = new System.Drawing.Point(6, 64);
            this.radioButtonAge.Name = "radioButtonAge";
            this.radioButtonAge.Size = new System.Drawing.Size(48, 16);
            this.radioButtonAge.TabIndex = 6;
            this.radioButtonAge.TabStop = true;
            this.radioButtonAge.Text = "AGE";
            this.radioButtonAge.UseVisualStyleBackColor = true;
            // 
            // FormSearch
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(314, 509);
            this.Controls.Add(this.buttonSearch);
            this.Controls.Add(this.textBoxContent);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.groupBox1);
            this.Name = "FormSearch";
            this.Text = "FormSearch";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.TextBox textBoxContent;
        private System.Windows.Forms.Button buttonSearch;
        private System.Windows.Forms.RadioButton radioButtonAge;
        private System.Windows.Forms.RadioButton radioButtonPhone;
        private System.Windows.Forms.RadioButton radioButtonName;
    }
}