# ChatX - 멀티플레이어 채팅 및 숫자야구 게임

언리얼 엔진 5를 사용한 멀티플레이어 채팅 및 숫자야구 게임 구현 프로젝트입니다.

## 개발 환경

- Unreal Engine 5.4
- Visual Studio 2022
- C++

## 게임 규칙

- 1~9 사이의 중복 없는 3자리 숫자를 맞추는 게임입니다
- 각 플레이어는 3번의 시도 기회가 있습니다
- 입력한 숫자와 정답을 비교하여 스트라이크(S)와 볼(B)로 결과를 알려줍니다
  - 자리와 숫자가 모두 같으면 스트라이크
  - 숫자는 같지만 자리가 다르면 볼
  - 하나도 맞지 않으면 OUT

## 구현 과정

### 1. 프로젝트 준비

1. UE5.4 기반 빈 C++ 프로젝트 생성
2. 빈 레벨(Empty Level) 생성 및 Maps 폴더에 "Chatting"으로 저장
3. 프로젝트 설정에서 기본 맵 지정
4. 게임 프레임워크를 위한 기본 클래스 구현:
   - `CXGameModeBase` (GameModeBase 상속)
   - `CXPlayerController` (PlayerController 상속)
5. 각 클래스의 블루프린트 생성 및 연결

### 2. 채팅 UI 구현

1. `CXChatInput` 클래스 및 `WBP_ChatInput` 위젯 블루프린트 생성
2. 위젯에 EditableTextBox 추가 및 레이아웃 설정
3. PlayerController에서 위젯 생성 및 표시
4. 채팅 입력 처리 로직 구현:
   - 텍스트 입력 시 PlayerController로 전달
   - 화면에 채팅 메시지 출력

### 3. 멀티플레이 기능 구현

1. 네트워크 디버깅을 위한 헬퍼 기능 구현:
   - `GetNetModeString` - 현재 네트워크 모드(서버/클라이언트) 확인
   - `GetRoleString` - 액터의 역할(Authority/Proxy) 확인
   - `MyPrintString` - 디버깅용 메시지 출력

2. RPC(Remote Procedure Call) 구현:
   - `ClientRPCPrintChatMessageString` - 클라이언트에 메시지 출력
   - `ServerRPCPrintChatMessageString` - 서버에 메시지 전송 및 모든 클라이언트에 브로드캐스트

3. 플레이어 상태 관리:
   - `CXPlayerState` 클래스 구현
   - 플레이어 이름 및 게임 정보 저장
   - Property Replication을 통한 상태 동기화

4. 게임 상태 관리:
   - `CXGameStateBase` 클래스 구현
   - 접속 알림 메시지 브로드캐스트

### 4. 숫자야구 게임 구현

1. 게임 로직 구현:
   - 서버에서 3자리 난수 생성
   - 사용자 입력 검증
   - 스트라이크/볼 판정 로직

2. 시도 횟수 관리:
   - 플레이어별 시도 횟수 저장 및 동기화
   - 최대 시도 횟수 제한 (3회)

3. 게임 판정 기능:
   - 승리 조건: 3스트라이크 달성
   - 무승부 조건: 모든 플레이어가 최대 시도 횟수 소진
   - 게임 리셋 기능

4. 공지 시스템:
   - `WBP_NotificationText` 위젯 구현
   - 게임 상태 및 결과 공지

## 주요 학습 내용

1. 언리얼 엔진의 네트워크 구조
   - 클라이언트-서버 모델
   - NetMode, NetRole, Authority와 Proxy 개념

2. 멀티플레이어 통신 방식
   - RPC(Remote Procedure Call)
   - Property Replication

3. 게임 프레임워크 구조
   - GameMode, GameState, PlayerController, PlayerState의 역할과 관계

## 주요 기능

- 멀티플레이어 지원
- 채팅 기반 명령어 입력
- 실시간 게임 상태 업데이트
- 승리/패배/무승부 판정
- 자동 게임 리셋

## 설치 방법

1. 레포지토리 클론
2. ChatX.uproject 파일을 더블클릭하여 언리얼 에디터 실행
3. 프로젝트 빌드
4. Play 버튼으로 게임 실행

## 게임 실행 방법

1. 서버 실행 (첫 번째 플레이어)
2. 클라이언트 접속 (다른 플레이어들)
3. 채팅창에 3자리 숫자 입력 (예: "123")
4. 결과 확인 및 다음 시도 