/******************************************************************************
 * Modulo Fonte..........: porting.h                                          *
 *                                                                            *
 * Data de criacao.......: 12/07/2013                                         *
 * Desenvolvedor.........: Henrique Hornos                                    *
 *                                                                            *
 *----------------------------------------------------------------------------*
 * Descricao.............:                                                    *
 * prototipos de funcoes do modulo porting.c                                  *
 *----------------------------------------------------------------------------*
 * Alteracoes............:                                                    *
 * Desenvolvedor.........:                                                    *
 * Data da alteracao.....:                                                    *
 *                                                                            *
 * "porting.h, v0.0.1 2013/07/11 20:45:00 id: "Henrique_H1"                   *
 *                                                                            *
 ******************************************************************************/
#ifndef PORTING_H
#define PORTING_H
#endif

/* defines de status do modem SDLC */
#define		SDLC_RESETED		0x0100
#define		SDLC_DIALLING		0x0200
#define		SDLC_CONNECTED		0x0300
#define		SDLC_ERRO_MDM		0x0400
#define		SDLC_NO_CARRIER		0x0500
#define		SDLC_NO_DIALTONE	0x0600
#define		SDLC_BUSY_DETECT	0x0700
#define		SDLC_NO_ANSWER		0x0800
#define		SDLC_ATCMD_TMO		0x0900

#define		AT_INIT_SDLC		 0				/* indice inicial de programacao do modem SDLC */
#define		AT_FIN_SDLC			 6				/* indice final de programacao do modem SDLC */
#define		AT_DISCA_SDLC		 7				/* indice do comando AT de discagem - necessario edita-lo anteriormente */
#define		AT_CMD_RESP			-1				/* obtem somente resposta do modem */

#define		TMO_DISC_SDLC		60000l			/* 60 segundos */
#define 	COM_TIMEOUT			20

#define		DTR_ON				0x01
#define		DTR_OFF				0x00
#define		RTS_ON				0x02
#define		RTS_OFF				0x00
#define		DTR_RTS_ON			0x03
#define		CTS_ON				0x20
#define		DCD_ON				0x08

/* defines BEEP POS */
#define		BEEP_DEFAULT	0x01
#define		BEEP_ERRO		0x02

/* estrutura de parametros SDLC */
struct PARM_SDLC
{
	uchar	atenuacao;							/* atenuacao da portadora (0-15) */
	BOOL	pulso;								/* modo de discagem */
	char	pabx[12];							/* string de PABX */
	uchar	ndial;								/* # de dials consecutivos */
	char	fone[12];							/* fone a ser discado */
	uchar	ntry;								/* # de tentativas por fone */
	uchar	tmo_idle;							/* time out para idle */
};

void	debugH			(char *, ...);

STAT	resetConsole	( void );
STAT	resetPrint		( void );

STAT	beepPOS			( char );
STAT	get_parm		( const char *, char *, int );
STAT	waitTime		( ulong );

int		writeDisp		( char *, int, int, int );
void	clearDisplay	( void );
char	readKeyPos		( void );
ulong	get_milli_sec	( void );

/* SDLC */
STAT	resetSDLC		( void );
STAT	SaveConfSDLC	( struct PARM * );
STAT	discaSDLC		( void );
STAT	chk_sdlc		( void );
STAT	getStatSDLC		( void );
STAT	sndSDLC			( char *, int );
STAT	recvSDLC		( char *, int * );

STAT	ATCmdSDLC		( int, int );

void	flushMDM		( void );
