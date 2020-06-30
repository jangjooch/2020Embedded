namespace _0622_Method01
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
            this.buttonProductCreate = new System.Windows.Forms.Button();
            this.buttonCre = new System.Windows.Forms.Button();
            this.buttonDis = new System.Windows.Forms.Button();
            this.buttonBoxCre = new System.Windows.Forms.Button();
            this.buttonBoxDis = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonProductCreate
            // 
            this.buttonProductCreate.Location = new System.Drawing.Point(12, 12);
            this.buttonProductCreate.Name = "buttonProductCreate";
            this.buttonProductCreate.Size = new System.Drawing.Size(75, 23);
            this.buttonProductCreate.TabIndex = 0;
            this.buttonProductCreate.Text = "CreateProduct";
            this.buttonProductCreate.UseVisualStyleBackColor = true;
            this.buttonProductCreate.Click += new System.EventHandler(this.buttonProductCreate_Click);
            // 
            // buttonCre
            // 
            this.buttonCre.Location = new System.Drawing.Point(12, 41);
            this.buttonCre.Name = "buttonCre";
            this.buttonCre.Size = new System.Drawing.Size(75, 23);
            this.buttonCre.TabIndex = 1;
            this.buttonCre.Text = "Create";
            this.buttonCre.UseVisualStyleBackColor = true;
            this.buttonCre.Click += new System.EventHandler(this.buttonCre_Click);
            // 
            // buttonDis
            // 
            this.buttonDis.Location = new System.Drawing.Point(93, 41);
            this.buttonDis.Name = "buttonDis";
            this.buttonDis.Size = new System.Drawing.Size(75, 23);
            this.buttonDis.TabIndex = 2;
            this.buttonDis.Text = "Dis";
            this.buttonDis.UseVisualStyleBackColor = true;
            this.buttonDis.Click += new System.EventHandler(this.buttonDis_Click);
            // 
            // buttonBoxCre
            // 
            this.buttonBoxCre.Location = new System.Drawing.Point(12, 70);
            this.buttonBoxCre.Name = "buttonBoxCre";
            this.buttonBoxCre.Size = new System.Drawing.Size(75, 23);
            this.buttonBoxCre.TabIndex = 3;
            this.buttonBoxCre.Text = "BoxCre";
            this.buttonBoxCre.UseVisualStyleBackColor = true;
            this.buttonBoxCre.Click += new System.EventHandler(this.buttonBoxCre_Click);
            // 
            // buttonBoxDis
            // 
            this.buttonBoxDis.Location = new System.Drawing.Point(93, 70);
            this.buttonBoxDis.Name = "buttonBoxDis";
            this.buttonBoxDis.Size = new System.Drawing.Size(75, 23);
            this.buttonBoxDis.TabIndex = 4;
            this.buttonBoxDis.Text = "BoxDis";
            this.buttonBoxDis.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(396, 247);
            this.Controls.Add(this.buttonBoxDis);
            this.Controls.Add(this.buttonBoxCre);
            this.Controls.Add(this.buttonDis);
            this.Controls.Add(this.buttonCre);
            this.Controls.Add(this.buttonProductCreate);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonProductCreate;
        private System.Windows.Forms.Button buttonCre;
        private System.Windows.Forms.Button buttonDis;
        private System.Windows.Forms.Button buttonBoxCre;
        private System.Windows.Forms.Button buttonBoxDis;
    }
}

