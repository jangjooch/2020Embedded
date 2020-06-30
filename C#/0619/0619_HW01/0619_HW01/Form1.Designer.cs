namespace _0619_HW01
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.textBoxInputName = new System.Windows.Forms.TextBox();
            this.textBoxInputPhone = new System.Windows.Forms.TextBox();
            this.textBoxInputAge = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.textBoxList = new System.Windows.Forms.TextBox();
            this.buttonSave = new System.Windows.Forms.Button();
            this.buttonSearch = new System.Windows.Forms.Button();
            this.textBoxSearchName = new System.Windows.Forms.TextBox();
            this.textBoxSearchPhone = new System.Windows.Forms.TextBox();
            this.textBoxSearchAge = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.buttonWrite = new System.Windows.Forms.Button();
            this.buttonLoad = new System.Windows.Forms.Button();
            this.buttonList = new System.Windows.Forms.Button();
            this.buttonReset = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBoxInputName
            // 
            this.textBoxInputName.Location = new System.Drawing.Point(87, 67);
            this.textBoxInputName.Name = "textBoxInputName";
            this.textBoxInputName.Size = new System.Drawing.Size(100, 21);
            this.textBoxInputName.TabIndex = 0;
            // 
            // textBoxInputPhone
            // 
            this.textBoxInputPhone.Location = new System.Drawing.Point(87, 94);
            this.textBoxInputPhone.Name = "textBoxInputPhone";
            this.textBoxInputPhone.Size = new System.Drawing.Size(100, 21);
            this.textBoxInputPhone.TabIndex = 1;
            // 
            // textBoxInputAge
            // 
            this.textBoxInputAge.Location = new System.Drawing.Point(87, 121);
            this.textBoxInputAge.Name = "textBoxInputAge";
            this.textBoxInputAge.Size = new System.Drawing.Size(100, 21);
            this.textBoxInputAge.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(40, 76);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 12);
            this.label1.TabIndex = 3;
            this.label1.Text = "NAME";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(40, 103);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 12);
            this.label2.TabIndex = 3;
            this.label2.Text = "PHONE";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(40, 130);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(30, 12);
            this.label3.TabIndex = 3;
            this.label3.Text = "AGE";
            // 
            // textBoxList
            // 
            this.textBoxList.Location = new System.Drawing.Point(230, 67);
            this.textBoxList.Multiline = true;
            this.textBoxList.Name = "textBoxList";
            this.textBoxList.Size = new System.Drawing.Size(384, 246);
            this.textBoxList.TabIndex = 4;
            // 
            // buttonSave
            // 
            this.buttonSave.Location = new System.Drawing.Point(112, 148);
            this.buttonSave.Name = "buttonSave";
            this.buttonSave.Size = new System.Drawing.Size(75, 23);
            this.buttonSave.TabIndex = 5;
            this.buttonSave.Text = "Save";
            this.buttonSave.UseVisualStyleBackColor = true;
            this.buttonSave.Click += new System.EventHandler(this.buttonSave_Click);
            // 
            // buttonSearch
            // 
            this.buttonSearch.Location = new System.Drawing.Point(53, 287);
            this.buttonSearch.Name = "buttonSearch";
            this.buttonSearch.Size = new System.Drawing.Size(75, 23);
            this.buttonSearch.TabIndex = 6;
            this.buttonSearch.Text = "Search";
            this.buttonSearch.UseVisualStyleBackColor = true;
            this.buttonSearch.Click += new System.EventHandler(this.buttonSearch_Click);
            // 
            // textBoxSearchName
            // 
            this.textBoxSearchName.Location = new System.Drawing.Point(87, 206);
            this.textBoxSearchName.Name = "textBoxSearchName";
            this.textBoxSearchName.Size = new System.Drawing.Size(100, 21);
            this.textBoxSearchName.TabIndex = 7;
            // 
            // textBoxSearchPhone
            // 
            this.textBoxSearchPhone.Location = new System.Drawing.Point(87, 233);
            this.textBoxSearchPhone.Name = "textBoxSearchPhone";
            this.textBoxSearchPhone.Size = new System.Drawing.Size(100, 21);
            this.textBoxSearchPhone.TabIndex = 8;
            // 
            // textBoxSearchAge
            // 
            this.textBoxSearchAge.Location = new System.Drawing.Point(87, 260);
            this.textBoxSearchAge.Name = "textBoxSearchAge";
            this.textBoxSearchAge.Size = new System.Drawing.Size(100, 21);
            this.textBoxSearchAge.TabIndex = 9;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(40, 215);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(41, 12);
            this.label4.TabIndex = 3;
            this.label4.Text = "NAME";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(34, 242);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(47, 12);
            this.label5.TabIndex = 3;
            this.label5.Text = "PHONE";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(51, 269);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(30, 12);
            this.label6.TabIndex = 3;
            this.label6.Text = "AGE";
            // 
            // buttonWrite
            // 
            this.buttonWrite.Location = new System.Drawing.Point(230, 38);
            this.buttonWrite.Name = "buttonWrite";
            this.buttonWrite.Size = new System.Drawing.Size(75, 23);
            this.buttonWrite.TabIndex = 10;
            this.buttonWrite.Text = "Write";
            this.buttonWrite.UseVisualStyleBackColor = true;
            this.buttonWrite.Click += new System.EventHandler(this.buttonWrite_Click);
            // 
            // buttonLoad
            // 
            this.buttonLoad.Location = new System.Drawing.Point(311, 38);
            this.buttonLoad.Name = "buttonLoad";
            this.buttonLoad.Size = new System.Drawing.Size(75, 23);
            this.buttonLoad.TabIndex = 11;
            this.buttonLoad.Text = "Load";
            this.buttonLoad.UseVisualStyleBackColor = true;
            this.buttonLoad.Click += new System.EventHandler(this.buttonLoad_Click);
            // 
            // buttonList
            // 
            this.buttonList.Location = new System.Drawing.Point(230, 9);
            this.buttonList.Name = "buttonList";
            this.buttonList.Size = new System.Drawing.Size(75, 23);
            this.buttonList.TabIndex = 12;
            this.buttonList.Text = "List";
            this.buttonList.UseVisualStyleBackColor = true;
            this.buttonList.Click += new System.EventHandler(this.buttonList_Click);
            // 
            // buttonReset
            // 
            this.buttonReset.Location = new System.Drawing.Point(134, 287);
            this.buttonReset.Name = "buttonReset";
            this.buttonReset.Size = new System.Drawing.Size(75, 23);
            this.buttonReset.TabIndex = 13;
            this.buttonReset.Text = "Reset";
            this.buttonReset.UseVisualStyleBackColor = true;
            this.buttonReset.Click += new System.EventHandler(this.buttonReset_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(626, 336);
            this.Controls.Add(this.buttonReset);
            this.Controls.Add(this.buttonList);
            this.Controls.Add(this.buttonLoad);
            this.Controls.Add(this.buttonWrite);
            this.Controls.Add(this.textBoxSearchAge);
            this.Controls.Add(this.textBoxSearchPhone);
            this.Controls.Add(this.textBoxSearchName);
            this.Controls.Add(this.buttonSearch);
            this.Controls.Add(this.buttonSave);
            this.Controls.Add(this.textBoxList);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxInputAge);
            this.Controls.Add(this.textBoxInputPhone);
            this.Controls.Add(this.textBoxInputName);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxInputName;
        private System.Windows.Forms.TextBox textBoxInputPhone;
        private System.Windows.Forms.TextBox textBoxInputAge;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBoxList;
        private System.Windows.Forms.Button buttonSave;
        private System.Windows.Forms.Button buttonSearch;
        private System.Windows.Forms.TextBox textBoxSearchName;
        private System.Windows.Forms.TextBox textBoxSearchPhone;
        private System.Windows.Forms.TextBox textBoxSearchAge;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button buttonWrite;
        private System.Windows.Forms.Button buttonLoad;
        private System.Windows.Forms.Button buttonList;
        private System.Windows.Forms.Button buttonReset;
    }
}

