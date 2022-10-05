package questao03.despesa;

import java.time.LocalDateTime;
import java.util.Objects;

import questao03.ITransacao;

public abstract class Despesa implements ITransacao{
	
	private LocalDateTime data;
	private String descricao;
	
	public abstract String getTipo();
	public abstract double calcularTotal();
	
	public Despesa(LocalDateTime data, String descricao) {
		super();
		this.setData(data);
		this.setDescricao(descricao);
	}
	
	public LocalDateTime getData() {
		return data;
	}
	
	public void setData(LocalDateTime data) {
		if(data != null) {
			this.data = data;
		}
	}
	
	public String getDescricao() {
		return descricao;
	}
	
	public void setDescricao(String descricao) {
		if(descricao != null) {
			this.descricao = descricao;
		}
	}
	
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Despesa other = (Despesa) obj;
		return Objects.equals(data, other.data) && Objects.equals(descricao, other.descricao);
	}

	@Override
	public String toString() {
		return "Despesa [data=" + data + ", descricao=" + descricao + "]";
	}
}
