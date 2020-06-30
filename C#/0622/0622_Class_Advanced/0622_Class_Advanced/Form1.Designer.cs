namespace _0622_Class_Advanced
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
            this.buttonAnimalCreate = new System.Windows.Forms.Button();
            this.buttonDogCreate = new System.Windows.Forms.Button();
            this.buttonCatCreate = new System.Windows.Forms.Button();
            this.buttonListAnimals = new System.Windows.Forms.Button();
            this.buttonTest = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonAnimalCreate
            // 
            this.buttonAnimalCreate.Location = new System.Drawing.Point(12, 12);
            this.buttonAnimalCreate.Name = "buttonAnimalCreate";
            this.buttonAnimalCreate.Size = new System.Drawing.Size(75, 23);
            this.buttonAnimalCreate.TabIndex = 0;
            this.buttonAnimalCreate.Text = "Animal";
            this.buttonAnimalCreate.UseVisualStyleBackColor = true;
            this.buttonAnimalCreate.Click += new System.EventHandler(this.Create_Animal);
            // 
            // buttonDogCreate
            // 
            this.buttonDogCreate.Location = new System.Drawing.Point(93, 12);
            this.buttonDogCreate.Name = "buttonDogCreate";
            this.buttonDogCreate.Size = new System.Drawing.Size(75, 23);
            this.buttonDogCreate.TabIndex = 1;
            this.buttonDogCreate.Text = "Dog";
            this.buttonDogCreate.UseVisualStyleBackColor = true;
            this.buttonDogCreate.Click += new System.EventHandler(this.Create_Dog);
            // 
            // buttonCatCreate
            // 
            this.buttonCatCreate.Location = new System.Drawing.Point(174, 12);
            this.buttonCatCreate.Name = "buttonCatCreate";
            this.buttonCatCreate.Size = new System.Drawing.Size(75, 23);
            this.buttonCatCreate.TabIndex = 2;
            this.buttonCatCreate.Text = "Cat";
            this.buttonCatCreate.UseVisualStyleBackColor = true;
            this.buttonCatCreate.Click += new System.EventHandler(this.Create_Cat);
            // 
            // buttonListAnimals
            // 
            this.buttonListAnimals.Location = new System.Drawing.Point(255, 12);
            this.buttonListAnimals.Name = "buttonListAnimals";
            this.buttonListAnimals.Size = new System.Drawing.Size(75, 23);
            this.buttonListAnimals.TabIndex = 3;
            this.buttonListAnimals.Text = "Animals";
            this.buttonListAnimals.UseVisualStyleBackColor = true;
            this.buttonListAnimals.Click += new System.EventHandler(this.buttonListAnimals_Click);
            // 
            // buttonTest
            // 
            this.buttonTest.Location = new System.Drawing.Point(12, 73);
            this.buttonTest.Name = "buttonTest";
            this.buttonTest.Size = new System.Drawing.Size(75, 23);
            this.buttonTest.TabIndex = 4;
            this.buttonTest.Text = "Test";
            this.buttonTest.UseVisualStyleBackColor = true;
            this.buttonTest.Click += new System.EventHandler(this.buttonTest_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(480, 323);
            this.Controls.Add(this.buttonTest);
            this.Controls.Add(this.buttonListAnimals);
            this.Controls.Add(this.buttonCatCreate);
            this.Controls.Add(this.buttonDogCreate);
            this.Controls.Add(this.buttonAnimalCreate);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonAnimalCreate;
        private System.Windows.Forms.Button buttonDogCreate;
        private System.Windows.Forms.Button buttonCatCreate;
        private System.Windows.Forms.Button buttonListAnimals;
        private System.Windows.Forms.Button buttonTest;
    }
}

