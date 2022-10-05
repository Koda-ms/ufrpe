package questao03.despesa;

import java.time.LocalDateTime;

public class DespesaComEnergia extends Despesa{
	public static final double VALOR_KWH = 0.50;
	
	private double kWh;
	
	public DespesaComEnergia(LocalDateTime data, String descricao, double kWh) {
		super(data, descricao);
		this.setkWh(kWh);
	}

	public void setkWh(double kWh) {
		if(kWh >= 0) {
			this.kWh = kWh;
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
		double valorAdicionalCada100kWh = (int)(this.kWh/100) * 1.20;
		
		if(this.kWh <= 50) {
			gastoTotal = (VALOR_KWH * this.kWh) + 2.0;
		} else if(this.kWh <= 200) {
			gastoTotal = (VALOR_KWH * this.kWh) + 15.0 + valorAdicionalCada100kWh;
			
		} else {
			gastoTotal = (VALOR_KWH * this.kWh) + 35.0 + valorAdicionalCada100kWh;
		}
		return gastoTotal;
	}

	@Override
	public String toString() {
		return String.format("%.1f kWh", kWh);
	}
}
