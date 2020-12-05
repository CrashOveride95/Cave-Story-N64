static const u8 pole_map[21*16] = {
  0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 
  0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 
  0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 
  0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 
  0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 
  0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x01, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 
  0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x01, 0x02, 0x03, 0x2B, 0x41, 0x40, 0x04, 0x01, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 
  0x30, 0x31, 0x30, 0x31, 0x30, 0x01, 0x01, 0x23, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00, 0x2B, 0x01, 0x30, 0x31, 0x30, 0x31, 0x30, 
  0x20, 0x21, 0x20, 0x21, 0x20, 0x01, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2E, 0x01, 0x20, 0x21, 0x20, 0x21, 0x20, 
  0x30, 0x31, 0x30, 0x31, 0x30, 0x01, 0x33, 0x1A, 0x10, 0x11, 0x00, 0x00, 0x00, 0x00, 0x10, 0x01, 0x30, 0x31, 0x30, 0x31, 0x30, 
  0x20, 0x21, 0x01, 0x21, 0x01, 0x01, 0x01, 0x01, 0x20, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x21, 0x20, 0x21, 0x20, 
  0x30, 0x31, 0x30, 0x31, 0x30, 0x01, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x01, 0x30, 0x31, 0x30, 0x31, 0x30, 
  0x20, 0x21, 0x20, 0x21, 0x20, 0x01, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 
  0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 
  0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21, 0x20, 
  0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 0x31, 0x30, 
};

static const EVENT pole_event[8] = {
  {7, 9, 0, 100, 0, 0x2000},
  {14, 9, 1640, 200, 15, 0x6000},
  {14, 8, 1640, 201, 21, 0x3800},
  {11, 9, 0, 0, 119, 0x0000},
  {10, 9, 1643, 301, 30, 0x2800},
  {10, 8, 1641, 300, 30, 0x7000},
  {9, 9, 1642, 310, 37, 0x2800},
  {9, 11, 0, 210, 0, 0x0000},
};

static const StageData pole_data = {
    21, 16,
    pole_map,
    8,
    pole_event,
    "#0090\n\
<MNA<CMU0008<FAI0000<END\n\
#0091\n\
<MNA<CMU0008<FAI0001<END\n\
#0092\n\
<MNA<CMU0008<FAI0002<END\n\
#0093\n\
<MNA<CMU0008<FAI0003<END\n\
#0094\n\
<MNA<CMU0008<FAI0004<END\n\
\n\
#0095\n\
<CMU0008<FAI0001<END\n\
\n\
#0100\n\
<PRI<FAO0000<TRA0012:0094:0053:0036\n\
\n\
\n\
\n\
#0200\n\
<KEY<FLJ1640:0201<FL+1640<SOU0022<CNP0200:0021:0000\n\
<MSGOpened the chest.<NOD<GIT0002<AM+0002:0000<CLR\n\
<CMU0010Got the =Polar Star=!<WAI0160<NOD<GIT0000<CLO<RMU\n\
<MSG\n\
From somewhere, a transmission...<FAO0004<NOD<TRA0018:0501:0002:0000\n\
\n\
#0201\n\
<PRI<MSGEmpty.<NOD<END\n\
\n\
#0210\n\
\n\
\n\
#0300\n\
<KEY<MSG*snore*<NOD<END\n\
\n\
#0301\n\
<FLJ1644:0303\n\
<KEY<MSGYou haven't seen the gun I made,\n\
have you?<NOD\n\
Someone went and stole it while\n\
I was sleeping!<NOD\n\
Drat, this is why I should've been\n\
keeping it in my pocket when\n\
I napped...<NOD<AMJ0002:0302<CLRIt wasn't even finished yet!<NOD\n\
Just a little more work and I\n\
might've been able to make a\n\
really fearsome weapon out of it.<NOD<CLR\n\
Ah, what a world, what a world...<NOD<END\n\
\n\
#0302\n\
<KEY<MSG<CMU0000<MYB0002\n\
HEY!!<NOD<CLRIsn't THAT my gun?!<NOD<CLR<GIT0002What are YOU doing with it?!\n\
I didn't make it for you!<NOD<CLRGive that back!<NOD<CLR<CNP0210:0150:0012<WAI0012<GIT0000<HMC\n\
=Polar Star= taken...<NOD<CLRPah!<NOD\n\
I see you've certainly been\n\
giving my gun a workout.<NOD<CLR\n\
.....<NOD<CLRYou know,<NOD\n\
I've long believed that one's\n\
weapons should be crafted by\n\
oneself.<NOD\n\
That one who fights with another's\n\
weapons and considers that force\n\
his own is witless.<NOD\n\
That one who blames his tools for\n\
that which his own power cannot\n\
achieve is a fool.<NOD<CLR\n\
<CMU0008However...<WAI0050<CLRWhen I see this gun before me that\n\
you have used so exhaustively,\n\
it moves this man to tears.<NOD\n\
To think such thorough use were\n\
possible even before the gun's\n\
completion...<NOD<CLR\n\
Hahhh...<NOD<CLRI apologize for my grumbling.<NOD<CLR\n\
You can keep this gun.<NOD<CMU0000<FAO0001\n\
After I finish it, of course.<NOD<CLO\n\
<WAI0150<FAI0001\n\
<FLA<WAI0050<TAM0002:0013:0000<FL+1644<FL+0303<MSG\n\
<CMU0010<MSG<GIT0013\n\
=Polar Star= became the =Spur=!<SMC<DNP0210<WAI0160<NOD<CMU0008<END\n\
\n\
#0303\n\
<KEY<MSGIn this world, there exists a\n\
balance between those who are\n\
creators and those who are users.<NOD<CLRI knew that, of course, but\n\
it took your help for me to\n\
experience this firsthand.<NOD\n\
From now on, I vow to dedicate\n\
myself to the side of creation.<NOD\n\
The labor involved becomes joy\n\
when I know there are those who\n\
will enjoy my work to the utmost.<NOD<END\n\
\n\
#0310\n\
<KEY<MSG<TUR\n\
\"Out.\"<NOD<END\n\
\n\
\n\
",
};
