# define MAXSTATION 10

typedef struct StationParam
{
	// ! ��λ��
	BYTE stationNo;
	// ����λ��
	BYTE stationName[100];
	// ��ת�������ƶ˿�
	BYTE rotatePort;
	// ! ת������
	BYTE rotateName[100];

	// ! �¶ȿ��Ʒ�ʽ GPIB/RS232 0/1
	BYTE tempControlMode;
	// ! RS232�˿�
	BYTE port;
	// ! GPIB��ַ
	BYTE addr;
	// ! ͨ����1
	BYTE channel1No;
	// ! ͨ����1����
	BYTE channel1Name[100];
	// ! ͨ����1����������
	BYTE channel1TempType;
	// ! ͨ����1�ȵ�ż������������������
	BYTE channel1TempSubmode;
	// ! ͨ����2
	BYTE channel2No;
	// ! ͨ����2����
	BYTE channel2Name[100];
	// ! ͨ����2����������
	BYTE channel2TempType;
	// ! ͨ����2�ȵ�ż������������������
	BYTE channel2TempSubmode;
	// ! ͨ����3
	BYTE channel3No;
	// ! ͨ����3����
	BYTE channel3Name[100];
	// ! ͨ����1����������
	BYTE channel3TempType;
	// ! ͨ����1�ȵ�ż������������������
	BYTE channel3TempSubmode;
	// ! ɨ����
	int nScanInterval;
	// ! �����ֶ�
	BYTE resverd[100];
}STATIONPARAM, *PSTATIONPARAM;

typedef struct GlobalParam
{
	// ! ��λ��
	int nStation;
	// ! ��λ����
	STATIONPARAM station[MAXSTATION];
	// ! �����ֶ�
	BYTE resvered[100];
}GLOBALPARAM, *PGLOBALPARAM;

// ! ϵͳ���ù�λ����
extern GLOBALPARAM g_Param;
// ��ϵͳ�ļ���ȡ��λ����
extern GLOBALPARAM g_SysParam;
// ! ����·��
extern CString              g_strExePath;
// �������ļ�����
extern CString              g_strSysFileName;