## 1. RTOS
### 1.1 RTOS is standard Real Time Operating System hay hệ điều hành thời gian thực được dùng trong các vi điều khiển để điều khiển thiết bị  một cách nhanh chóng và đa nhiệm (multi tasking).

#### Operating System: 
- Hệ điều hành là một tập hợp các chương trình được thiết kế để quản lý tất cả các tài nguyên của máy tính. Nói cách khác, một tập hợp các chương trình đóng vai trò trung gian giữa người dùng máy tính và phần cứng máy tính.

- Bộ nhớ, thiết bị I/O, thiết bị liên lạc, v.v. là tài nguyên phần cứng của máy tính. Hệ thống tệp, bộ nhớ ảo, bảo mật, v.v. là tài nguyên phần mềm. Bây giờ một tập hợp các chương trình được sử dụng để quản lý tất cả các tài nguyên này được gọi là hệ điều hành.

#### Shell
- Shell is the program that handles all other programs.( Shell là chương trình xử lý tất cả các chương trình khác)

##### For example:
- K- shell or Born shell in UNIX
- Explorer.exe in windows
- Command program in DOS

#### Kernel
- The kernel provides the most basic control over all of the computer’s hardware devices. Time management, task scheduling, memory management, file system, etc. all are monitored by the Kernel.
( Cung cấp khả năng kiểm soát cơ bản nhất đối với tất cả các thiết bị phần cứng của máy tính. Quản lý thời gian, lập lịch tác vụ, quản lý bộ nhớ, hệ thống tệp, v.v. đều được Kernel giám sát.)
![alt text](images/3.png)
### 1.2 Các đặc trưng của RTOS.
- High performance.
- Safety and security.
- Priority-based scheduling.
- Small.
### 1.3 Cách hoạt động của RTOS.
Điều phối các Task, lập lịch và phân mức ưu tiên cho Task (Cơ chế Multi-Tasking)

![anh](images/1.png)
- Nó cứ bị scheduler đá qua đá lại giữa các trạng thái — giống kiểu con người khi làm việc thì lúc đang gõ code, lúc thì đứng chờ compile, lúc thì bỏ đó đi pha cà phê.

![alt text](images/2.png)

#### RUNNING:
- CPU hiện giờ đang dành cho task này.
- Nó đang thực sự chạy code.
#### READY:
- đã đủ điều kiện để chạy.
- chỉ là phải… chờ scheduler.
- giống kiểu “tôi sẵn rồi, cho tôi slot CPU đi”.
#### BLOCKED: Dừng tạm thời chờ chạy lại
- đang đợi 1 cái gì đó: delay() hết thời gian, queue có dữ liệu, semaphore release…
- bản chất: nó không chạy, nhưng cũng không rảnh — nó chờ điều kiện.
#### SUSPEND: kiểu “freezer”, bị người khác tạm cất vào tủ. Nếu ko phá “freezer” băng sẽ dừng đó mãi mãi.
### 1.3 Scheduling
#### Priority-based Preemptive Scheduling 
- Mỗi task được gán một mức ưu tiên (Priority), và RTOS sẽ luôn chọn task có mức ưu tiên cao nhất để chạy. Nếu một task mới có mức ưu tiên cao hơn task đang chạy, RTOS sẽ tạm hoãn task đang chạy và chuyển sang task có mức ưu tiên cao hơn.
- RTOS sử dụng một hàng đợi ưu tiên cho các task sẵn sàng thực thi. Khi một task sẵn sàng chạy, hệ thống sẽ chọn task có mức ưu tiên cao nhất từ hàng đợi để thực thi.
#### Tóm tắt Task
![alt text](images/4.png)
1. Độ ưu tiên cao hơn -> chạy trước.
2. Nếu thằng có độ ưu tiên cao nó ko bị block hoặc dừng lại bởi 1 cơ chế nào đó -> kernel sẽ không cấp tài nguyên cho thằng task nào khác.
- Link: https://khuenguyencreator.com/stm32-rtos-cac-trang-thai-cua-task/
![alt text](images/6.png)
![alt text](images/5.png)
- HAL_delay -> gây delay cho cả hệ thống, dùng khi ko yêu cầu chặt chẽ về
- os_delay (delay trong task. khi bị delay những task khác có thể chạy,  )