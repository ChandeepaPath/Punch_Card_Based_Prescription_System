#define LCD_Dir DDRB   /* Define LCD data port direction */
#define LCD_Port PORTB /* Define LCD data port */
#define RS PD3		   /* Define Register Select (data reg./command reg.) signal pin */
#define RW PD6
#define EN PB4 /* Define Enable signal pin */

void LCD_Command(unsigned char cmnd)
{
	LCD_Port = (LCD_Port & 0xF0) | (cmnd >> 4); /* sending upper nibble */
	PORTD &= ~(1 << RS);						/* RS=0, command reg. */
	PORTD &= ~(1 << RW);
	LCD_Port |= (1 << EN); /* Enable pulse */
	_delay_us(1);
	LCD_Port &= ~(1 << EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0xF0) | (cmnd & 0x0F); /* sending lower nibble */
	LCD_Port |= (1 << EN);
	_delay_us(1);
	LCD_Port &= ~(1 << EN);
	_delay_ms(2);
}

void LCD_Char(unsigned char data)
{
	LCD_Port = (LCD_Port & 0xF0) | (cmnd >> 4); /* sending upper nibble */
	PORTD |= (1 << RS);							/* RS=0, command reg. */
	PORTD &= ~(1 << RW);
	LCD_Port |= (1 << EN); /* Enable pulse */
	_delay_us(1);
	LCD_Port &= ~(1 << EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0xF0) | (cmnd & 0x0F); /* sending lower nibble */
	LCD_Port |= (1 << EN);
	_delay_us(1);
	LCD_Port &= ~(1 << EN);
	_delay_ms(2);
}

void LCD_Init(void) /* LCD Initialize function */
{
	LCD_Dir |= 0x1F; /* Make LCD command port direction as o/p */
	DDRD |= (1 << RS) | (1 << RW);
	_delay_ms(20); /* LCD Power ON delay always >15ms */

	LCD_Command(0x33);
	LCD_Command(0x32); /* send for 4 bit initialization of LCD  */
	LCD_Command(0x28); /* Use 2 line and initialize 5*7 matrix in (4-bit mode)*/
	LCD_Command(0x0c); /* Display on cursor off*/
	LCD_Command(0x06); /* Increment cursor (shift cursor to right)*/
	LCD_Command(0x01); /* Clear display screen*/
	_delay_ms(2);
	LCD_Command(0x80); /* Cursor 1st row 0th position */
}

void LCD_String(char *str) /* Send string to LCD function */
{
	int i;
	for (i = 0; str[i] != 0; i++) /* Send each char of string till the NULL */
	{
		LCD_Char(str[i]);
	}
}

void LCD_String_xy(char row, char pos, char *str) /* Send string to LCD with xy position */
{
	if (row == 0 && pos < 16)
		LCD_Command((pos & 0x0F) | 0x80); /* Command of first row and required position<16 */
	else if (row == 1 && pos < 16)
		LCD_Command((pos & 0x0F) | 0xC0); /* Command of first row and required position<16 */
	LCD_String(str);					  /* Call LCD string function */
}

void LCD_Clear()
{
	LCD_Command(0x01); /* Clear display */
	_delay_ms(2);
	LCD_Command(0x80); /* Cursor 1st row 0th position */
}