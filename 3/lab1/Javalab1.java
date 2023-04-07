package pl.edu.pg.eti.ksg.po.lab1;

import pl.edu.pg.eti.ksg.po.lab1.transformacje.*;

public class Javalab1 {
    public static void main(String[] args)
    {
        zlozenieTransformacjiDzialanie();
    }

    private static void punktDzialanie() {
        /**
         * Zadanie 1
         * Prezentacja działania klasy Punkt
         */

        Punkt p1 = new Punkt(1, 2);
        System.out.println(p1);
        System.out.println(p1.getX() + " " + p1.getY());
        System.out.println(p1.hashCode());

        Punkt p2 = new Punkt(1, 2);

        System.out.println(p2 == p1);
        System.out.println(p2.equals(p1));

        System.out.println(Punkt.O);
        System.out.println(Punkt.E_X);
        System.out.println(Punkt.E_Y);
    }

    private static void transformacjaDzialanie() {
        /**
         * Zadanie 2
         * Prezentacja działania klasy bazujących na Transformacja
         */

        /*
         * Konstrukcja językowa try {} catch (...){} służy do
         * obsługi wyjątków. Kod w bloku try jest monitorowany
         * pod kątem wystąpienia wyjątku bądź wyjątków
         * wspomnianych na początku bloku/bloków catch.
         * Jeżeli gdzieś w bloku try wystąpi wyjątek, to sterowanie
         * zostanie natychmiast przeniesione do bloku catch.
         * Tam powinien znajdować się kod obsługujący wyjątek.
         * Może to być np. wypisanie stosu wywołań na wyjście błędów
         * lub zapisanie wyjątku w logach, lub wyrzucenie (zgłoszenie)
         * innego wyjątku lepiej opisującego sytuacje (można załączyć
         * wyjątek który zainicjował to zdarzenie patrz. Konstruktor
         * klasy java.lang.Exception)
         */
        try {
            Punkt p1 = Punkt.E_X;
            System.out.println(p1);
            Transformacja tr = new Translacja(5, 6);
            System.out.println(tr);
            Punkt p2 = tr.transformuj(p1);
            System.out.println(p2);
            Transformacja trr = tr.getTransformacjaOdwrotna();
            System.out.println(trr);
            Punkt p3 = trr.transformuj(p2);
            System.out.println(p3);

        } catch (BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }
        System.out.println();

        try
        {
            Punkt p1 = new Punkt(2, 2);
            System.out.println(p1);
            Transformacja tr2 = new Skalowanie(5, 4);
            System.out.println(tr2);
            Punkt p2 = tr2.transformuj(p1);
            System.out.println(p2);
            Transformacja trr2 = tr2.getTransformacjaOdwrotna();
            System.out.println(trr2);
            Punkt p3 = trr2.transformuj(p2);
            System.out.println(p3);
        }
        catch(BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }
        System.out.println();

        try
        {
            Punkt p1 = new Punkt(2, 2);
            Transformacja tr2 = new Skalowanie(5, 0);
            System.out.println(tr2);
            System.out.println(p1);
            Punkt p2 = tr2.transformuj(p1);
            System.out.println(p2);
            Transformacja trr2 = tr2.getTransformacjaOdwrotna();
            System.out.println(trr2);
            Punkt p3 = trr2.transformuj(p2);
            System.out.println(p3);
        }
        catch(BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }
        System.out.println();
    }

    private static void obrotDzialanie() {
        /**
         * Zadanie 3
         * Prezentacja działania klasy Obrot
         */

        Obrot o1 = new Obrot(Math.PI / 4);
        System.out.println(o1);

        Punkt p1 = new Punkt(1, 1);

        Punkt p2 = o1.transformuj(p1);
        System.out.println(p2);

        Transformacja o2 = o1.getTransformacjaOdwrotna();
        System.out.println(o2);

        Punkt p3 = o2.transformuj(p2);
        System.out.println(p3);
    }

    private static void zlozenieTransformacjiDzialanie() {
        /**
         * Zadanie 4
         * Prezentacja działania klasy ZlozenieTransformacji
         */

        Transformacja t1 = new Translacja(1, 1);
        Transformacja t2 = new Skalowanie(2, 2);
        Transformacja t3 = new Obrot(Math.PI / 4);

        Transformacja z1 = new ZlozenieTransformacji(t1, t2, t3);
        System.out.println(z1);

        Punkt p1 = new Punkt(1, 1);
        Punkt p2 = z1.transformuj(p1);

        System.out.println(p2);

        try {
            Transformacja z2 = z1.getTransformacjaOdwrotna();

            Punkt p3 = z2.transformuj(p2);
            System.out.println(p3);
        } catch (Exception e) {
            System.out.println("Nie można odwrócić złożenia transformacji");
        }
    }
}
