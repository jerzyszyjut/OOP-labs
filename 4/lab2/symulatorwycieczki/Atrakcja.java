package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki;

public abstract class Atrakcja implements ElementWycieczki {
    protected final double wymaganyCzas;

    protected Atrakcja(double wymaganyCzas) {
        this.wymaganyCzas = wymaganyCzas;
    }

    public double getWymaganyCzas() {
        return wymaganyCzas;
    }
}
