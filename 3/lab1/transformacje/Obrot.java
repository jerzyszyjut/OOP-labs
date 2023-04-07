package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class Obrot implements Transformacja {
    private final double kat;

    public Obrot(double kat) {
        this.kat = kat;
    }

    @Override
    public Punkt transformuj(Punkt p) {
        return new Punkt(
                Math.round(p.getX() * Math.cos(kat) - p.getY() * Math.sin(kat)),
                Math.round(p.getX() * Math.sin(kat) + p.getY() * Math.cos(kat))
        );
    }

    @Override
    public Transformacja getTransformacjaOdwrotna() {
        return new Obrot(-kat);
    }

    public double getKat() {
        return kat;
    }

    @Override
    public String toString() {
        return "Obrot o " + kat + " radianow";
    }
}
