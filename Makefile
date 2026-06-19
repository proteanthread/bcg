CC = gcc
CFLAGS = -std=c17 -pedantic -Wall -Wno-unused-label -I.
LDFLAGS = -lm
SRCDIR = SOURCE
BINDIR = BINARY

TARGETS = $(BINDIR)/23matches $(BINDIR)/3dplot $(BINDIR)/aceyducey $(BINDIR)/amazing $(BINDIR)/animal $(BINDIR)/awari $(BINDIR)/bagels $(BINDIR)/banner $(BINDIR)/basketball $(BINDIR)/batnum $(BINDIR)/battle $(BINDIR)/blackjack $(BINDIR)/bombardment $(BINDIR)/bombsaway $(BINDIR)/bounce $(BINDIR)/bowling $(BINDIR)/boxing $(BINDIR)/bug $(BINDIR)/bullfight $(BINDIR)/bullseye $(BINDIR)/bunny $(BINDIR)/buzzword $(BINDIR)/calendar $(BINDIR)/change $(BINDIR)/checkers $(BINDIR)/chemist $(BINDIR)/chief $(BINDIR)/chomp $(BINDIR)/civilwar $(BINDIR)/combat $(BINDIR)/craps $(BINDIR)/cube $(BINDIR)/depthcharge $(BINDIR)/diamond $(BINDIR)/dice $(BINDIR)/digits $(BINDIR)/evenwins $(BINDIR)/flipflop $(BINDIR)/football $(BINDIR)/ftball $(BINDIR)/furtrader $(BINDIR)/gameofevenwins $(BINDIR)/golf $(BINDIR)/gomoko $(BINDIR)/guess $(BINDIR)/gunner $(BINDIR)/hammurabi $(BINDIR)/hangman $(BINDIR)/hello $(BINDIR)/hexapawn $(BINDIR)/hi-lo $(BINDIR)/highiq $(BINDIR)/hockey $(BINDIR)/horserace $(BINDIR)/hurkle $(BINDIR)/kinema $(BINDIR)/king $(BINDIR)/lem $(BINDIR)/letter $(BINDIR)/life $(BINDIR)/lifefortwo $(BINDIR)/litquiz $(BINDIR)/love $(BINDIR)/lunar $(BINDIR)/mastermind $(BINDIR)/mathdice $(BINDIR)/mine $(BINDIR)/mugwump $(BINDIR)/name $(BINDIR)/nicomachus $(BINDIR)/nim $(BINDIR)/number $(BINDIR)/onecheck $(BINDIR)/orbit $(BINDIR)/pizza $(BINDIR)/poetry $(BINDIR)/poker $(BINDIR)/qubit $(BINDIR)/queen $(BINDIR)/reverse $(BINDIR)/rocket $(BINDIR)/rockscissors $(BINDIR)/roulette $(BINDIR)/russianroulette $(BINDIR)/salvo $(BINDIR)/sinewave $(BINDIR)/slalom $(BINDIR)/slots $(BINDIR)/splat $(BINDIR)/stars $(BINDIR)/stockmarket $(BINDIR)/suite $(BINDIR)/superstartrek $(BINDIR)/superstartrekins $(BINDIR)/synonym $(BINDIR)/target $(BINDIR)/test $(BINDIR)/tictactoe1 $(BINDIR)/tictactoe2 $(BINDIR)/tower $(BINDIR)/train $(BINDIR)/trap $(BINDIR)/war $(BINDIR)/weekday $(BINDIR)/word

all: $(BINDIR) $(TARGETS)

$(BINDIR):
	mkdir -p $(BINDIR)

$(BINDIR)/23matches: $(SRCDIR)/23matches.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/3dplot: $(SRCDIR)/3dplot.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/aceyducey: $(SRCDIR)/aceyducey.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/amazing: $(SRCDIR)/amazing.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/animal: $(SRCDIR)/animal.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/awari: $(SRCDIR)/awari.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/bagels: $(SRCDIR)/bagels.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/banner: $(SRCDIR)/banner.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/basketball: $(SRCDIR)/basketball.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/batnum: $(SRCDIR)/batnum.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/battle: $(SRCDIR)/battle.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/blackjack: $(SRCDIR)/blackjack.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/bombardment: $(SRCDIR)/bombardment.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/bombsaway: $(SRCDIR)/bombsaway.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/bounce: $(SRCDIR)/bounce.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/bowling: $(SRCDIR)/bowling.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/boxing: $(SRCDIR)/boxing.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/bug: $(SRCDIR)/bug.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/bullfight: $(SRCDIR)/bullfight.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/bullseye: $(SRCDIR)/bullseye.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/bunny: $(SRCDIR)/bunny.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/buzzword: $(SRCDIR)/buzzword.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/calendar: $(SRCDIR)/calendar.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/change: $(SRCDIR)/change.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/checkers: $(SRCDIR)/checkers.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/chemist: $(SRCDIR)/chemist.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/chief: $(SRCDIR)/chief.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/chomp: $(SRCDIR)/chomp.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/civilwar: $(SRCDIR)/civilwar.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/combat: $(SRCDIR)/combat.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/craps: $(SRCDIR)/craps.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/cube: $(SRCDIR)/cube.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/depthcharge: $(SRCDIR)/depthcharge.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/diamond: $(SRCDIR)/diamond.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/dice: $(SRCDIR)/dice.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/digits: $(SRCDIR)/digits.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/evenwins: $(SRCDIR)/evenwins.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/flipflop: $(SRCDIR)/flipflop.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/football: $(SRCDIR)/football.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/ftball: $(SRCDIR)/ftball.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/furtrader: $(SRCDIR)/furtrader.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/gameofevenwins: $(SRCDIR)/gameofevenwins.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/golf: $(SRCDIR)/golf.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/gomoko: $(SRCDIR)/gomoko.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/guess: $(SRCDIR)/guess.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/gunner: $(SRCDIR)/gunner.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/hammurabi: $(SRCDIR)/hammurabi.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/hangman: $(SRCDIR)/hangman.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/hello: $(SRCDIR)/hello.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/hexapawn: $(SRCDIR)/hexapawn.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/hi-lo: $(SRCDIR)/hi-lo.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/highiq: $(SRCDIR)/highiq.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/hockey: $(SRCDIR)/hockey.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/horserace: $(SRCDIR)/horserace.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/hurkle: $(SRCDIR)/hurkle.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/kinema: $(SRCDIR)/kinema.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/king: $(SRCDIR)/king.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/lem: $(SRCDIR)/lem.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/letter: $(SRCDIR)/letter.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/life: $(SRCDIR)/life.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/lifefortwo: $(SRCDIR)/lifefortwo.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/litquiz: $(SRCDIR)/litquiz.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/love: $(SRCDIR)/love.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/lunar: $(SRCDIR)/lunar.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/mastermind: $(SRCDIR)/mastermind.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/mathdice: $(SRCDIR)/mathdice.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/mine: $(SRCDIR)/mine.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/mugwump: $(SRCDIR)/mugwump.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/name: $(SRCDIR)/name.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/nicomachus: $(SRCDIR)/nicomachus.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/nim: $(SRCDIR)/nim.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/number: $(SRCDIR)/number.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/onecheck: $(SRCDIR)/onecheck.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/orbit: $(SRCDIR)/orbit.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/pizza: $(SRCDIR)/pizza.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/poetry: $(SRCDIR)/poetry.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/poker: $(SRCDIR)/poker.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/qubit: $(SRCDIR)/qubit.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/queen: $(SRCDIR)/queen.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/reverse: $(SRCDIR)/reverse.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/rocket: $(SRCDIR)/rocket.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/rockscissors: $(SRCDIR)/rockscissors.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/roulette: $(SRCDIR)/roulette.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/russianroulette: $(SRCDIR)/russianroulette.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/salvo: $(SRCDIR)/salvo.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/sinewave: $(SRCDIR)/sinewave.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/slalom: $(SRCDIR)/slalom.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/slots: $(SRCDIR)/slots.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/splat: $(SRCDIR)/splat.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/stars: $(SRCDIR)/stars.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/stockmarket: $(SRCDIR)/stockmarket.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/suite: $(SRCDIR)/suite.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/superstartrek: $(SRCDIR)/superstartrek.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/superstartrekins: $(SRCDIR)/superstartrekins.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/synonym: $(SRCDIR)/synonym.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/target: $(SRCDIR)/target.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/test: $(SRCDIR)/test.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/tictactoe1: $(SRCDIR)/tictactoe1.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/tictactoe2: $(SRCDIR)/tictactoe2.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/tower: $(SRCDIR)/tower.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/train: $(SRCDIR)/train.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/trap: $(SRCDIR)/trap.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/war: $(SRCDIR)/war.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/weekday: $(SRCDIR)/weekday.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BINDIR)/word: $(SRCDIR)/word.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -rf $(BINDIR)
