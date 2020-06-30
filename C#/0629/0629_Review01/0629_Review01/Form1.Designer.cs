namespace _0629_Review01
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
            this.buttonListAdd = new System.Windows.Forms.Button();
            this.buttonListShow = new System.Windows.Forms.Button();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.buttonDicAdd = new System.Windows.Forms.Button();
            this.buttonDicShow = new System.Windows.Forms.Button();
            this.buttonListRemove = new System.Windows.Forms.Button();
            this.buttonDicRemove = new System.Windows.Forms.Button();
            this.textBoxListRemoveContent = new System.Windows.Forms.TextBox();
            this.textBoxDicRemoveContent = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // buttonListAdd
            // 
            this.buttonListAdd.Location = new System.Drawing.Point(12, 12);
            this.buttonListAdd.Name = "buttonListAdd";
            this.buttonListAdd.Size = new System.Drawing.Size(75, 23);
            this.buttonListAdd.TabIndex = 0;
            this.buttonListAdd.Text = "ListAdd";
            this.buttonListAdd.UseVisualStyleBackColor = true;
            this.buttonListAdd.Click += new System.EventHandler(this.ListAdd);
            // 
            // buttonListShow
            // 
            this.buttonListShow.Location = new System.Drawing.Point(93, 12);
            this.buttonListShow.Name = "buttonListShow";
            this.buttonListShow.Size = new System.Drawing.Size(75, 23);
            this.buttonListShow.TabIndex = 1;
            this.buttonListShow.Text = "ListShow";
            this.buttonListShow.UseVisualStyleBackColor = true;
            this.buttonListShow.Click += new System.EventHandler(this.ListShow);
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(12, 70);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(249, 218);
            this.richTextBox1.TabIndex = 2;
            this.richTextBox1.Text = "";
            // 
            // buttonDicAdd
            // 
            this.buttonDicAdd.Location = new System.Drawing.Point(12, 41);
            this.buttonDicAdd.Name = "buttonDicAdd";
            this.buttonDicAdd.Size = new System.Drawing.Size(75, 23);
            this.buttonDicAdd.TabIndex = 3;
            this.buttonDicAdd.Text = "DicAdd";
            this.buttonDicAdd.UseVisualStyleBackColor = true;
            this.buttonDicAdd.Click += new System.EventHandler(this.DicAdd);
            // 
            // buttonDicShow
            // 
            this.buttonDicShow.Location = new System.Drawing.Point(93, 41);
            this.buttonDicShow.Name = "buttonDicShow";
            this.buttonDicShow.Size = new System.Drawing.Size(75, 23);
            this.buttonDicShow.TabIndex = 4;
            this.buttonDicShow.Text = "DicShow";
            this.buttonDicShow.UseVisualStyleBackColor = true;
            this.buttonDicShow.Click += new System.EventHandler(this.DicShow);
            // 
            // buttonListRemove
            // 
            this.buttonListRemove.Location = new System.Drawing.Point(174, 12);
            this.buttonListRemove.Name = "buttonListRemove";
            this.buttonListRemove.Size = new System.Drawing.Size(111, 23);
            this.buttonListRemove.TabIndex = 5;
            this.buttonListRemove.Text = "ListRemove";
            this.buttonListRemove.UseVisualStyleBackColor = true;
            this.buttonListRemove.Click += new System.EventHandler(this.ListRemove);
            // 
            // buttonDicRemove
            // 
            this.buttonDicRemove.Location = new System.Drawing.Point(174, 41);
            this.buttonDicRemove.Name = "buttonDicRemove";
            this.buttonDicRemove.Size = new System.Drawing.Size(111, 23);
            this.buttonDicRemove.TabIndex = 6;
            this.buttonDicRemove.Text = "DicRemove";
            this.buttonDicRemove.UseVisualStyleBackColor = true;
            this.buttonDicRemove.Click += new System.EventHandler(this.DicRemove);
            // 
            // textBoxListRemoveContent
            // 
            this.textBoxListRemoveContent.Location = new System.Drawing.Point(291, 14);
            this.textBoxListRemoveContent.Name = "textBoxListRemoveContent";
            this.textBoxListRemoveContent.Size = new System.Drawing.Size(100, 21);
            this.textBoxListRemoveContent.TabIndex = 7;
            // 
            // textBoxDicRemoveContent
            // 
            this.textBoxDicRemoveContent.Location = new System.Drawing.Point(291, 43);
            this.textBoxDicRemoveContent.Name = "textBoxDicRemoveContent";
            this.textBoxDicRemoveContent.Size = new System.Drawing.Size(100, 21);
            this.textBoxDicRemoveContent.TabIndex = 8;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(412, 300);
            this.Controls.Add(this.textBoxDicRemoveContent);
            this.Controls.Add(this.textBoxListRemoveContent);
            this.Controls.Add(this.buttonDicRemove);
            this.Controls.Add(this.buttonListRemove);
            this.Controls.Add(this.buttonDicShow);
            this.Controls.Add(this.buttonDicAdd);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.buttonListShow);
            this.Controls.Add(this.buttonListAdd);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonListAdd;
        private System.Windows.Forms.Button buttonListShow;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.Button buttonDicAdd;
        private System.Windows.Forms.Button buttonDicShow;
        private System.Windows.Forms.Button buttonListRemove;
        private System.Windows.Forms.Button buttonDicRemove;
        private System.Windows.Forms.TextBox textBoxListRemoveContent;
        private System.Windows.Forms.TextBox textBoxDicRemoveContent;
    }
}

