package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class ZlozenieTransformacji implements Transformacja {
    private final Transformacja[] transformacje;

    public ZlozenieTransformacji(Transformacja... transformacje) {
        this.transformacje = transformacje;
    }

    @Override
    public Punkt transformuj(Punkt p) {
        Punkt wynik = p;
        for (Transformacja t : transformacje) {
            wynik = t.transformuj(wynik);
        }
        return wynik;
    }

    @Override
    public Transformacja getTransformacjaOdwrotna() {
        Transformacja[] odwrotnosci = new Transformacja[transformacje.length];

        try {
            for (int i = 0; i < transformacje.length; i++) {
                odwrotnosci[i] = transformacje[transformacje.length - i - 1].getTransformacjaOdwrotna();
            }
        } catch (Exception e) {
            System.out.println("Nie mozna odwrocic co najmniej jednej transformacji");
        }
        return new ZlozenieTransformacji(odwrotnosci);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Transformacja t : transformacje) {
            sb.append(t.toString()).append(" -> ");
        }
        sb.delete(sb.length() - 4, sb.length());
        return sb.toString();
    }

    public Transformacja[] getTransformacje() {
        return transformacje;
    }
}
