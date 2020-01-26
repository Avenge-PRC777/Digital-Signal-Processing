im=imread('test_image1.jpg');
imnew=(0.11*im(:,:,1)+0.59*im(:,:,2)+0.3*im(:,:,3));
imnew1=((im(:,:,1)/3)+(im(:,:,2)/3)+(im(:,:,3)/3));
%figure, imshow(imnew);title("Red less");
%figure, imshow(imnew1);title("Equal contrib");
z=corr2(imnew,imnew1);
darkim=imread('test_image2.jpg');
darkgray=darkim(:,:,1)/3+darkim(:,:,2)/3+darkim(:,:,3)/3;
%figure, imshow(darkim);title("Red less");
%figure, imshow(darkgray);title("Equal contrib");
meanv=mean(mean(darkgray));
modev=mode(mode(darkgray));
medv=median(median(darkgray));
thres=12;
%[level,ef]=graythresh(darkgray);
clearimg=imbinarize(darkgray,0.034);%darkgray>th;
figure, imshow(clearimg);title("Cleared");
part1=darkgray(:,1:199);
part2=darkgray(:,200:800);

part2=imbinarize(part2,0.034);
part1=imbinarize(part1,0.08);

whole=ones(450,800);
whole(:,1:199)=part1;
whole(:,200:800)=part2;
figure, imshow(whole,[]);

%moving average
newim=imread('test_image1.jpg');
[l,b,c]=size(newim);
kernel_size=3;
kernel=zeros(kernel_size,kernel_size);
newmo