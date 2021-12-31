# RandomOTP_Generator






20161511김영민

OTP 4자리 랜덤 발생기


CNSL 연구회에서 자체개발한 탭으로 진행



![그림1](https://user-images.githubusercontent.com/62790857/147810727-6eba94d8-7958-4330-8755-525534441956.png)
입력받은 숫자 Serial.parseInt()메소드를 토대로 진행하였기 때문에 line ending없음이 아니라 새 줄로 실행하게 되면 0의값이 출력되어서 line ending으로 변경 후 진행하였습니다.

![그림6](https://user-images.githubusercontent.com/62790857/147810743-4f3981b2-7d5b-46d1-a1c0-17fed8d9c6c5.png)



자체개발 탭


![그림2](https://user-images.githubusercontent.com/62790857/147810754-84af80ca-4a4f-4f32-9e44-8a6d767899b7.png)



저는 4자리의 OTP를 사용하기위해 100이아닌 10000으로 나누어 6자리가아닌 4자리의 랜덤 숫자를 사용하였습니다.

시리얼 통신화면으로 랜덤 생성한 OTP의 확인하기위해 Serial.available 사용후 parseInt를 이용해 입력받은 값과 비교하였습니다.

현재 랜덤 생성시킨 값이 0을 출력하는 부분이 있기 때문에, 
조건을 주어 4자리 미만이거나 5자리의 수를 출력하게 된다면, 
자체적으로 random함수를 사용해 임의의 4자리의 OTP를 생성하도록 만들었습니다.


이 OTP 프로그램은 먼저 임의적으로 생성한 4자리의 난수를 알려주고
5초안에 4자리 번호를 맞게 입력한다면 currect가 출력되고, 입력하지 못하거나
틀리게 된다면 fail의 값을 반환하는 프로그램입니다.







OTP 4자리 숫자를 제대로 입력하였을때 : 
![그림3](https://user-images.githubusercontent.com/62790857/147810763-b0b0252a-daf4-4460-9dd9-aab4a167f0cc.png)


OTP 4자리 숫자를 잘못 입력하였을 때:
![그림4](https://user-images.githubusercontent.com/62790857/147810767-ea23552c-a489-48bc-8e82-89f6a955bb65.png)


OTP 4자리 숫자를 입력하지 않았을 때 :
![그림5](https://user-images.githubusercontent.com/62790857/147810772-62c51682-5dd4-426a-948d-c90d78b91eb6.png)

