namespace _0622_ClassAdvanced_Form
{
    partial class FormMain
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
            this.buttonForm = new System.Windows.Forms.Button();
            this.buttonNewDialog = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonForm
            // 
            this.buttonForm.Location = new System.Drawing.Point(12, 12);
            this.buttonForm.Name = "buttonForm";
            this.buttonForm.Size = new System.Drawing.Size(124, 23);
            this.buttonForm.TabIndex = 0;
            this.buttonForm.Text = "NewForm";
            this.buttonForm.UseVisualStyleBackColor = true;
            this.buttonForm.Click += new System.EventHandler(this.buttonForm_Click);
            // 
            // buttonNewDialog
            // 
            this.buttonNewDialog.Location = new System.Drawing.Point(12, 41);
            this.buttonNewDialog.Name = "buttonNewDialog";
            this.buttonNewDialog.Size = new System.Drawing.Size(124, 23);
            this.buttonNewDialog.TabIndex = 1;
            this.buttonNewDialog.Text = "New Dialog";
            this.buttonNewDialog.UseVisualStyleBackColor = true;
            this.buttonNewDialog.Click += new System.EventHandler(this.buttonNewDialog_Click);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(412, 303);
            this.Controls.Add(this.buttonNewDialog);
            this.Controls.Add(this.buttonForm);
            this.Name = "FormMain";
            this.Text = "Main";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonForm;
        private System.Windows.Forms.Button buttonNewDialog;
    }
}

