# \# Kiểm Tra Đặc Tính Bộ Mã - Lý Thuyết Thông Tin




##### \## 1. Mô tả dự án

Đây là chương trình C++ được viết để giải quyết Phần 2 của bài tập Lý thuyết thông tin. Chương trình nhận đầu vào là các bộ mã và tiến hành kiểm tra 3 tính chất:

\- Tính suy biến: Kiểm tra xem có từ mã nào bị trùng lặp hay không.

\- Tính Prefix (Mã tiền tố): Kiểm tra xem có từ mã nào là phần đầu của một từ mã khác không.

\- Khả năng giải mã duy nhất: Sử dụng thuật toán Sardinas-Patterson để kiểm tra.



##### \## 2. Cấu trúc thư mục

CodingTheory/

|-- README.md           (Tài liệu hướng dẫn hiện tại)

|-- src/

|   |-- main.cpp        (Mã nguồn C++ chính)

|-- tests/

|   |-- test***n***.in        (File chứa dữ liệu đầu vào mẫu)

|   |-- test***n***.out       (File chứa kết quả đầu ra tương ứng)



##### \## 3. Cách biên dịch và chạy chương trình



Yêu cầu hệ thống

\*  Trình biên dịch C++ (GCC/G++ hoặc Clang) hỗ trợ chuẩn C++11 trở lên.

\*  Hệ điều hành: Windows, macOS, hoặc Linux.



Bạn cần mở Terminal (hoặc Command Prompt) và ***di chuyển vào thư mục dự án***.



###### Bước 1: Biên dịch

Chạy lệnh sau để biên dịch file mã nguồn:

**g++ src/main.cpp -o main**



###### Bước 2: Chạy chương trình với testcase

Sử dụng lệnh chuyển hướng để đọc file input:

\- Trên **Windows**:

main.exe < tests\\test***n***.in ( ***n*** là trường hợp bạn muốn thử )

\- Trên **Linux** / macOS:

./main < tests/test***n***.in ( ***n*** là trường hợp bạn muốn thử )



###### Bước 3: Đối chiếu với test***n***.out



##### \## 4. Định dạng dữ liệu đầu vào (Input)

Bạn có thể tự kiểm tra với input của mình

File input cần được viết theo cấu trúc sau:

\- Dòng đầu tiên: số nguyên output\_mode - chế độ trắc nghiệm hoặc tự luận ( 1 là trắc nghiệm, 2 là tự luận )

\- Dòng thứ 2 : số nguyên t ( số lượng testcase )

\- Các dòng tiếp theo chia làm từng cụm cho mỗi testcase:

* Dòng 1: Số nguyên N (số lượng từ mã).
* Dòng 2: N từ mã, viết cách nhau bởi khoảng trắng.

