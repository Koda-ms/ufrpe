package questao03.despesa;

import java.time.LocalDateTime;

public class DespesaComAgua extends Despesa{
	public static final double TARIFA_MINIMA_AGUA = 45.0;
	
	private double totalM3;

	public DespesaComAgua(LocalDateTime data, String descricao, double totalM3) {
		super(data, descricao);
		this.setTotalM3(totalM3);
	}

	public void setTotalM3(double totalM3) {
		if(totalM3 >= 0) {
			this.totalM3 = totalM3;
		}
	}

	@Override
	public LocalDateTime getData() {
		return super.getData();
	}

	@Override
	public String getDescricao() {
		return super.getDescricao();
	}

	@Override
	public String getTipo() {
		return "Despesa";
	}

	@Override
	public double calcularTotal() {
		double gastoTotal = 0;
		if(this.totalM3 <= 10) {
			gastoTotal = TARIFA_MINIMA_AGUA;
		} else if(this.totalM3 <= 20) {
			gastoTotal = TARIFA_MINIMA_AGUA + ((this.totalM3 - 10) * 5.0);
		} else {
			gastoTotal = TARIFA_MINIMA_AGUA + ((this.totalM3 - 20) * 6.0) + (5.0 * 10.0); //Adding the exceeded from 11 to 20 m³
		}
		return gastoTotal;
	}
	
	@Override
	public String toString() {
		return String.format("%.1f m³", totalM3);
	}
}
